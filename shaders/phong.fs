#version 330

#define MAX_LIGHTS 4

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

out vec4 frag_colour;
in vec4 world_pos;
in vec3 world_norm;
uniform mat4 view;
uniform Light lights[MAX_LIGHTS];

vec3 AddPointLight(Light light, vec3 normal, vec3 view_dir){
    vec3 light_dir = normalize(light.position.xyz - world_pos.xyz);
    float diff = max(dot(light_dir, normal), 0.0);

    vec3 reflect_dir = reflect(-light_dir, normal);
    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);

    vec3 ambient = vec3( 0.1, 0.1, 0.1);
    vec3 diffuse = diff * vec3( 0.385, 0.647, 0.812);
    vec3 specular = spec * vec3( 0.385, 0.647, 0.812);
    specular = diff <= 0.0 ? vec3(0, 0, 0) : specular;
    return ambient + diffuse + specular;
}

void main () {
    vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
    vec4 color = vec4( 0.385, 0.647, 0.812, 1.0);

    vec3 normal = normalize(world_norm);
    vec3 camera_pos = vec3(inverse(view)[3]);
    vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);

    vec3 result = vec3(0, 0, 0);
    for(int i = 0; i < 2; i++){
        result += AddPointLight(lights[i], normal, view_dir);
    }

    frag_colour = vec4(result, 1);
}