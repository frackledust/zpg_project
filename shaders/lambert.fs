#version 330
    out vec4 frag_colour;
    in vec4 world_pos;
    in vec3 world_norm;
    uniform vec3 light;
    void main () {
        vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

        vec4 color = vec4( 0.385, 0.647, 0.812, 1.0);

        vec3 light_vec = normalize(light.xyz - world_pos.xyz);
        float dot_product = max(dot(light_vec, normalize(world_norm)), 0.0);
        vec4 diffuse = dot_product * vec4( 0.385, 0.647, 0.812, 1.0);
        frag_colour = ambient + diffuse;
    }