#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include "VAO.h"
#include "VBO.h"
#include "ShaderManager.h"
#include "Window.h"
#include "App.h"
#include "CallbackController.h"

float points[] = {
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
};

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


int main(void)
{
    App* app = new App(800, 600);
    CallbackController::bind_callbacks();

    auto* my_window = app->window;
//    my_window->bind_callbacks();

    //what is this?
    glfwSwapInterval(1);

    VBO(sizeof(b), b);
    VAO * vao = new VAO();
    vao->add_vertex(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(0* sizeof(float)));
    vao->add_vertex(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4* sizeof(float)));

    //create and compile shaders
    auto *shaderManager = new ShaderManager();
    shaderManager->add_shader(GL_VERTEX_SHADER, &vertex_shader);
    shaderManager->add_shader(GL_FRAGMENT_SHADER, &fragment_shader);
    shaderManager->link_shaders();

    while (app->is_open()) {
        app->draw_frame(shaderManager, vao);
    }

    delete app;
    exit(EXIT_SUCCESS);
}
