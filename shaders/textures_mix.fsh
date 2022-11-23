#version 330
out vec4 frag_colour;

in vec4 world_pos;
in vec3 world_norm;
in vec2 uv;

uniform sampler2D texture_0;
uniform sampler2D texture_1;
void main () {
    frag_colour = mix(texture(texture_0, uv), texture(texture_1, uv), 0.2);
}