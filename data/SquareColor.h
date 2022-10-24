//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_SQUARECOLOR_H
#define ZPG_PROJECT_SQUARECOLOR_H
const int VERTEX_SIZE = 3;

const char* vertex_shader_phong =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=1) in vec3 vc;"
        "out vec4 world_pos;"
        "out vec3 world_norm;"
        "uniform mat4 model;"
        "uniform mat4 view;"
        "uniform mat4 projection;"
        "void main () {"
        "     gl_Position = projection * view * model * vec4(vp, 1);"
        "     world_pos = model * vec4(vp, 1.0f);"
        "     world_norm = normalize(transpose(inverse(mat3(model))) * vc);"
        "}";

const char* fragment_shader_phong =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec4 world_pos;"
        "in vec3 world_norm;"
        "uniform mat4 view;"
        "void main () {"
        "     vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);"
        ""
        "     vec3 light = vec3(0, 0, 0);"
        "     vec4 color = vec4( 0.385, 0.647, 0.812, 1.0);"
        ""
        "     light = normalize(light.xyz - world_pos.xyz);"
        "     float dot_product = max(dot(light, normalize(world_norm)), 0.0);"
        "     vec4 diffuse = dot_product * vec4( 0.385, 0.647, 0.812, 1.0);"
        ""
        "     float specular_strength = 1;"
        "     vec3 camera_pos = vec3(inverse(view)[3]);"
        "     vec3 view_dir = normalize(camera_pos.xyz - world_pos.xyz);"
        "     vec3 reflect_dir = reflect(-light, normalize(world_norm));"
        "     float spec = pow(max(dot(view_dir, reflect_dir), 0.0), 32);"
        "     vec4 specular =  spec < 0 ? vec4(0, 0, 0, 0) : specular_strength * spec * color;"
        "     frag_colour = ambient + diffuse + specular;"
        "}";

const char* fragment_shader_lamber =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec4 world_pos;"
        "in vec3 world_norm;"
        "void main () {"
        "     vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);"
        ""
        "     vec3 light = vec3(1, 0, 0.0);"
        "     light = normalize(light.xyz - world_pos.xyz);"
        "     float dot_product = max(dot(light, normalize(world_norm)), 0.0);"
        "     vec4 diffuse = dot_product * vec4( 0.385, 0.647, 0.812, 1.0);"
        "     frag_colour = ambient + diffuse;"
        "}";

const char* vertex_shader_no_col =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=1) in vec3 vc;"
        "out vec4 colors;"
        "uniform mat4 model;"
        "uniform mat4 view;"
        "uniform mat4 projection;"
        "void main () {"
        "     gl_Position = projection * view * model * vec4(vp, 1);"
        "     colors = vec4(vp, 1);"
        "}";

const char* vertex_shader =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=1) in vec3 vc;"
        "out vec4 colors;"
        "uniform mat4 model;"
        "uniform mat4 view;"
        "uniform mat4 projection;"
        "void main () {"
        "     gl_Position = projection * view * model * vec4(vp, 1);"
        "     colors = vec4(vc, 1);"
        "}";
const char* fragment_shader =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec4 colors;"
        "void main () {"
        "     frag_colour = colors;"
        "}";


const int VERTEX_COUNT = 36;
const float data[] ={
        -1.0f,-1.0f,-1.0f,0.583f,  0.771f,  0.014f,
        -1.0f,-1.0f, 1.0f,0.609f,  0.115f,  0.436f,
        -1.0f, 1.0f, 1.0f,0.327f,  0.483f,  0.844f,

        1.0f, 1.0f,-1.0f, 0.822f,  0.569f,  0.201f,
        -1.0f,-1.0f,-1.0f,0.435f,  0.602f,  0.223f,
        -1.0f, 1.0f,-1.0f,0.310f,  0.747f,  0.185f,

        1.0f,-1.0f, 1.0f,0.597f,  0.770f,  0.761f,
        -1.0f,-1.0f,-1.0f,0.559f,  0.436f,  0.730f,
        1.0f,-1.0f,-1.0f,0.359f,  0.583f,  0.152f,

        1.0f, 1.0f,-1.0f,0.483f,  0.596f,  0.789f,
        1.0f,-1.0f,-1.0f, 0.559f,  0.861f,  0.639f,
        -1.0f,-1.0f,-1.0f, 0.195f,  0.548f,  0.859f,

        -1.0f,-1.0f,-1.0f,0.014f,  0.184f,  0.576f,
        -1.0f, 1.0f, 1.0f,0.771f,  0.328f,  0.970f,
        -1.0f, 1.0f,-1.0f,0.406f,  0.615f,  0.116f,

        1.0f,-1.0f, 1.0f,0.676f,  0.977f,  0.133f,
        -1.0f,-1.0f, 1.0f,0.971f,  0.572f,  0.833f,
        -1.0f,-1.0f,-1.0f,0.140f,  0.616f,  0.489f,

        -1.0f, 1.0f, 1.0f,0.997f,  0.513f,  0.064f,
        -1.0f,-1.0f, 1.0f,0.945f,  0.719f,  0.592f,
        1.0f,-1.0f, 1.0f,0.543f,  0.021f,  0.978f,

        1.0f, 1.0f, 1.0f,0.279f,  0.317f,  0.505f,
        1.0f,-1.0f,-1.0f,0.167f,  0.620f,  0.077f,
        1.0f, 1.0f,-1.0f,0.347f,  0.857f,  0.137f,

        1.0f,-1.0f,-1.0f,0.055f,  0.953f,  0.042f,
        1.0f, 1.0f, 1.0f,0.714f,  0.505f,  0.345f,
        1.0f,-1.0f, 1.0f,0.783f,  0.290f,  0.734f,

        1.0f, 1.0f, 1.0f,0.722f,  0.645f,  0.174f,
        1.0f, 1.0f,-1.0f,0.302f,  0.455f,  0.848f,
        -1.0f, 1.0f,-1.0f,0.225f,  0.587f,  0.040f,

        1.0f, 1.0f, 1.0f,0.517f,  0.713f,  0.338f,
        -1.0f, 1.0f,-1.0f,0.053f,  0.959f,  0.120f,
        -1.0f, 1.0f, 1.0f,0.393f,  0.621f,  0.362f,

        1.0f, 1.0f, 1.0f,0.673f,  0.211f,  0.457f,
        -1.0f, 1.0f, 1.0f,0.820f,  0.883f,  0.371f,
        1.0f,-1.0f, 1.0f,0.982f,  0.099f,  0.879f
};
#endif //ZPG_PROJECT_SQUARECOLOR_H
