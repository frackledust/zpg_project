#version 330

#define MAX_LIGHTS 4
#define DIR 1
#define POINT 2
#define SPOT 3

float light_constant = 1.0f;
float light_linear = 0.35f;
float light_quadratic = 0.44f;


struct Light {
    int type;
    vec3 position;
    vec3 direction;

    float cut_off;
    vec3 color;
};

out vec4 frag_colour;
in vec4 world_pos;
in vec3 world_norm;
in vec2 uv;

uniform sampler2D ourTexture;
uniform mat4 view;
uniform Light spotlight;
uniform Light lights[MAX_LIGHTS];

vec3 AddDirLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(-light.direction.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);

    vec3 diffuse = diff * light.color;
    vec3 specular = spec * light.color;
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return diffuse + specular;
}

vec3 AddPointLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz);
    float attenuation = max(1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2)), 0);

    vec3 diffuse = diff * light.color * attenuation;
    vec3 specular = spec * light.color * attenuation;
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return diffuse + specular;
}

vec3 AddSpotLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz / world_pos.w);
    float attenuation = 1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2));

    float theta = dot(light_dir, normalize(-light.direction));

    if (theta > light.cut_off){
        float intensity = 0.f + 1.f/ (1.f - light.cut_off) * (theta - light.cut_off);

        vec3 diffuse = diff * light.color * attenuation * intensity;
        vec3 specular = spec * vec3(1, 1, 1) * attenuation * intensity;
        specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
        return diffuse + specular;
    }
    return vec3(0);
}

void main () {
    vec3 normal = normalize(world_norm);
    vec3 camera_pos = vec3(inverse(view)[3]);
    vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);

    vec3 result = texture(ourTexture, uv).rgb;
    for (int i = 0; i < MAX_LIGHTS; i++){
        if (lights[i].type == SPOT){
            result += AddSpotLight(lights[i], normal, view_dir);
        }
        else if (lights[i].type == POINT){
            result += AddPointLight(lights[i], normal, view_dir);
        }
        else if (lights[i].type == DIR){
            result += AddDirLight(lights[i], normal, view_dir);
        }
    }

    if (spotlight.type == SPOT){
        result += AddSpotLight(spotlight, normal, view_dir);
    }

    frag_colour = vec4(result, 1);
}