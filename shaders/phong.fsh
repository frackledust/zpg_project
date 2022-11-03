#version 330

#define MAX_LIGHTS 4
#define DIR 1
#define POINT 2
#define SPOT 3

float light_constant = 1.0f;
float light_linear = 0.09f;
float light_quadratic = 0.032f;


struct Light {
    float type;
    vec3 position;
    vec3 direction;

    float cut_off;
    float out_cut_off;
};

out vec4 frag_colour;
in vec4 world_pos;
in vec3 world_norm;
uniform mat4 view;
uniform Light spotlight;
uniform Light lights[MAX_LIGHTS];

vec3 AddDirLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(-light.direction.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);

    vec3 ambient = vec3( 0.1, 0.1, 0.1);
    vec3 diffuse = diff * vec3( 0.385, 0.647, 0.812);
    vec3 specular = spec * vec3( 0.385, 0.647, 0.812);
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return ambient + diffuse + specular;
}

vec3 AddPointLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz);
    float attenuation = 1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2));

    vec3 ambient = vec3( 0.1, 0.1, 0.1) * attenuation;
    vec3 diffuse = diff * vec3( 0.385, 0.647, 0.812) * attenuation;
    vec3 specular = spec * vec3( 0.385, 0.647, 0.812) * attenuation;
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return ambient + diffuse + specular;
}

vec3 AddSpotLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
    float distance = length(light.position - world_pos.xyz);
    float attenuation = 1.0 / (light_constant + light_linear * distance + light_quadratic * pow(distance, 2));

    float theta = dot(light_dir, normalize(-light.direction));
    float epsilon = light.cut_off - light.out_cut_off;
    float intensity = clamp((theta - light.out_cut_off) / epsilon, 0.0, 1.0);

    vec3 ambient = vec3( 0.1, 0.1, 0.1) * attenuation * intensity;
    vec3 diffuse = diff * vec3( 0.385, 0.647, 0.812) * attenuation * intensity;
    vec3 specular = spec * vec3( 0.385, 0.647, 0.812) * attenuation * intensity;
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return (ambient + diffuse + specular);
}

void main () {
    vec3 normal = normalize(world_norm);
    vec3 camera_pos = vec3(inverse(view)[3]);
    vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);

    vec3 result = vec3( 0.1, 0.1, 0.1);
    for(int i = 0; i < 2; i++){
        if(lights[i].type == SPOT){
            result += AddSpotLight(lights[i], normal, view_dir);
        }
        else if(lights[i].type == POINT){
            result += AddPointLight(lights[i], normal, view_dir);
        }
        else if(lights[i].type == DIR){
            result += AddDirLight(lights[i], normal, view_dir);
        }
    }

    if(spotlight.type == SPOT){
        result += AddSpotLight(spotlight, normal, view_dir);
    }

    frag_colour = vec4(result, 1);
}