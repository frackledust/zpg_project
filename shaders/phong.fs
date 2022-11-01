#version 330
    out vec4 frag_colour;
    in vec4 world_pos;
    in vec3 world_norm;
    uniform mat4 view;
    uniform vec3 light;
    void main () {
        vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

        vec3 normal = normalize(world_norm);

        vec4 color = vec4( 0.385, 0.647, 0.812, 1.0);

        vec3 light_dir = normalize(light.xyz - world_pos.xyz);
        float dot_product = max(dot(light_dir, normal), 0.0);
        vec4 diffuse = dot_product * color;

        float specular_strength = 1;
        vec3 camera_pos = vec3(inverse(view)[3]);

        vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);
        vec3 reflect_dir = reflect(-light_dir, normal);

        float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);
        vec4 specular = specular_strength * spec * color;
        // specular = dot_product <= 0.0 ? vec4(0, 0, 0, 0) : specular;
        frag_colour = ambient + diffuse + specular;
}