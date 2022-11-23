#version 330
layout(location=0) in vec3 vp;
layout(location=1) in vec3 vn;
layout (location=2) in vec2 vuv;
layout(location = 3) in vec3 tg;

out vec4 world_pos;
out vec3 world_norm;
out vec2 uv;
out mat3 tbn;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main () {
    gl_Position = projection * view * model * vec4(vp, 1);

    world_pos = model * vec4(vp, 1.0f);

    mat3 normal_mat = transpose(inverse(mat3(model)));
    world_norm = normalize(normal_mat * vn);
    uv = vuv;

    //Gram-Schmidt orthonormalization -> 3 perpendicular vectors
    vec3 normal = normalize(vn);
    vec3 tangent = normalize(tg);
    tangent = normalize(tangent - dot(tangent, normal) * normal);
    vec3 bitangent = cross(normal, tangent);

    //TBN Matrix
    vec3 T = normalize(vec3(normal_mat * tangent));
    vec3 B = normalize(vec3(normal_mat * bitangent));
    vec3 N = normalize(vec3(normal_mat * normal));
    tbn = mat3(T, B, N);
}