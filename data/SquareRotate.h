//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_SQUAREROTATE_H
#define ZPG_PROJECT_SQUAREROTATE_H

#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/glm.hpp>

const glm::mat4 M = glm::rotate(glm::mat4(1.0f), 1.0f, glm::vec3(0.0f, 0.0f, 1.0f));
const glm::mat4 M2 = glm::rotate(glm::mat4(1.0f), 3.14f, glm::vec3(0.0f, 0.0f, 1.0f));

const float c[4][2][4] ={
        { { -1, -.5f, .5f, 1 }, { 1, 1, 1, 1 } },
        { { -1, .5f, .5f, 1 }, { 1, 0, 1, 1 } },
        { { -0.7, .5f, .5f, 1 }, { 0, 0, 1, 1 } },
        { { -0.7, -.5f, .5f, 1 }, { 0, 1, 1, 1 } },
};

const float b[4][2][4] ={
        { { -.5f, -.5f, .5f, 1 }, { 1, 1, 0, 1 } },
        { { -.5f, .5f, .5f, 1 }, { 1, 0, 0, 1 } },
        { { .5f, .5f, .5f, 1 }, { 0, 1, 0, 1 } },
//        { { .5f, -.5f, .5f, 1 }, { 0, 1, 0, 1 } },
};

const char* vertex_shader =
        "#version 330\n"
        "layout(location=0) in vec4 vp;"
        "layout(location=1) in vec4 vc;"
        "uniform mat4 modelMatrix;"
        "out vec4 colors;"
        "void main () {"
        "     gl_Position = modelMatrix * vp;"
        "     colors = vc;"
        "}";
const char* fragment_shader =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec4 colors;"
        "void main () {"
        "     frag_colour = colors;"
        "}";

#endif //ZPG_PROJECT_SQUAREROTATE_H
