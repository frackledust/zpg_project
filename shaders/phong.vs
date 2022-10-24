#version 330
    layout(location=0) in vec3 vp;
    layout(location=1) in vec3 vc;
    out vec4 world_pos;
    out vec3 world_norm;
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;
    void main () {
    gl_Position = projection * view * model * vec4(vp, 1);
    world_pos = model * vec4(vp, 1.0f);
    world_norm = normalize(transpose(inverse(mat3(model))) * vc);
}