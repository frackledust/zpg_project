#version 330
out vec4 frag_colour;

in vec4 world_pos;
in vec3 world_norm;
in vec2 uv;

uniform sampler2D ourTexture;
void main () {
    frag_colour = texture(ourTexture, uv);
}