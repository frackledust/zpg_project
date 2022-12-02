#version 330

#define MAX_LIGHTS 4
#define DIR 1
#define POINT 2
#define SPOT 3

int normal_intensity_const = 1;
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
in mat3 tbn;

uniform sampler2D texture_0;
uniform sampler2D texture_1;

uniform mat4 view;
uniform Light spotlight;
uniform Light lights[MAX_LIGHTS];

vec4 AddDirLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(-light.direction.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);

    vec4 diffuse = diff * vec4(light.color, 1) * texture(texture_0, uv);
    vec4 specular = spec * vec4(1);
    specular = diff <= 0.0 ? vec4(0) : specular;
    return diffuse + specular;
}

vec4 AddPointLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz);
    float attenuation = max(1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2)), 0);

    vec4 diffuse = diff * attenuation * vec4(light.color, 1) * texture(texture_0, uv);
    vec4 specular = spec * attenuation * vec4(1);
    specular = diff <= 0.0 ? vec4(0) : specular;
    return diffuse + specular;
}

vec4 AddSpotLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz / world_pos.w);
    float attenuation = 1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2));

    float theta = dot(light_dir, normalize(-light.direction));

    if (theta > light.cut_off){
        float intensity = 0.f + 1.f/ (1.f - light.cut_off) * (theta - light.cut_off);

        vec4 diffuse = diff * attenuation * intensity * vec4(light.color, 1) * texture(texture_0, uv);
        vec4 specular = spec * vec4(1) * attenuation * intensity;
        specular = diff <= 0.0 ? vec4(0) : specular;
        return diffuse + specular;
    }
    return vec4(0);
}

void main () {
    vec3 encoded_normal = texture(texture_1, uv).rgb;
    encoded_normal = 2.0 * encoded_normal - 1.0;//RGB to vector interval < -1, 1 >
    encoded_normal = normalize(encoded_normal * vec3(1, 1, normal_intensity_const));
    vec3 normal = normalize(tbn * encoded_normal);


    vec3 camera_pos = vec3(inverse(view)[3]);
    vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);

    vec4 result = texture(texture_0, uv);

    for (int i = 0; i < 2; i++){
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

    frag_colour = result;
}