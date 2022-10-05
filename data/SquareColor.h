//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_SQUARECOLOR_H
#define ZPG_PROJECT_SQUARECOLOR_H

const float b[4][2][4] ={
        { { -.5f, -.5f, .5f, 1 }, { 1, 1, 0, 1 } },
        { { -.5f, .5f, .5f, 1 }, { 1, 0, 0, 1 } },
        { { .5f, .5f, .5f, 1 }, { 0, 0, 0, 1 } },
        { { .5f, -.5f, .5f, 1 }, { 0, 1, 0, 1 } },
};

const char* vertex_shader =
        "#version 330\n"
        "layout(location=0) in vec4 vp;"
        "layout(location=1) in vec4 vc;"
        "out vec4 colors;"
        "void main () {"
        "     gl_Position = vp;"
        "     colors = vc;"
        "}";
const char* fragment_shader =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec4 colors;"
        "void main () {"
        "     frag_colour = colors;"
        "}";

#endif //ZPG_PROJECT_SQUARECOLOR_H
