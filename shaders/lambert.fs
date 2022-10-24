#version 330
    out vec4 frag_colour;
    in vec4 world_pos;
    in vec3 world_norm;
    void main () {
        vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);

        vec3 light = vec3(0, 0, 0);
        vec4 color = vec4( 0.385, 0.647, 0.812, 1.0);

        light = normalize(light.xyz - world_pos.xyz);
        float dot_product = max(dot(light, normalize(world_norm)), 0.0);
        vec4 diffuse = dot_product * vec4( 0.385, 0.647, 0.812, 1.0);
        frag_colour = ambient + diffuse;
    }