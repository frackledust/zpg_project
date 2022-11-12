#version 330
layout(location=0) in vec3 vp;
layout(location=1) in vec3 vc;
layout (location=2) in vec2 vuv;
out vec4 colors;
out vec2 uv;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main () {
    gl_Position = projection * view * model * vec4(vp, 1);
    colors = vec4(vc, 1);
    uv = vuv;
}