#version 330
out vec4 frag_colour;

void main () {
    vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
    frag_colour = ambient;
}