#version 330
    out vec4 frag_colour;
    in vec4 colors;
    void main () {
        frag_colour = colors;
    }