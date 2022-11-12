#version 330
out vec4 frag_colour;
in vec4 colors;
in vec2 uv;

uniform sampler2D ourTexture;
void main () {
    frag_colour = colors;
    frag_colour = texture(ourTexture, uv);
}