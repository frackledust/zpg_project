#version 330
layout (location = 0) in vec3 aPos;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main(){
    TexCoords = aPos;
    mat4 view_2 = mat4(mat3(view)); // smazat posun kamery, zústane jen rotace
    vec4 pos = projection * view_2 * vec4(aPos, 1.0);
    gl_Position = pos.xyww;
}