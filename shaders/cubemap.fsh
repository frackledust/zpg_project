#version 330
out vec4 frag_color;

in vec3 uv;

uniform samplerCube skybox;

void main(){
    frag_color = texture(skybox, uv);
}