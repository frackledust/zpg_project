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

static void error_callback(int error, const char* description){ fputs(description, stderr); }
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}
static void window_focus_callback(GLFWwindow* window, int focused){ printf("window_focus_callback \n"); }
static void window_iconify_callback(GLFWwindow* window, int iconified){ printf("window_iconify_callback \n"); }
static void window_size_callback(GLFWwindow* window, int width, int height){
    printf("resize %d, %d \n", width, height);
    glViewport(0, 0, width, height);
}

static void cursor_callback(GLFWwindow *window, double x, double y){ printf("cursor_callback \n"); }

static void button_callback(GLFWwindow* window, int button, int action, int mode){
    if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

float points[] = {
        1.f, 0.f, 0.f,
        0.f, 1.f, 1.f,
        .5f, -.5f, .5f
};

const float b[4][2][4] ={
        { { -.5f, -.5f, .5f, 1 }, { 1, 1, 0, 1 } },
        { { -.5f, .5f, .5f, 1 }, { 1, 0, 0, 1 } },
        { { .5f, .5f, .5f, 1 }, { 0, 0, 0, 1 } },
        { { .5f, -.5f, .5f, 1 }, { 0, 1, 0, 1 } },
};

const char* vertex_shader =
        "#version 330\n"
        "layout(location=0) in vec3 vp;"
        "layout(location=4) in vec3 vc;"
        "out vec3 colors;"
        "void main () {"
        "     gl_Position = vec4 (vp, 1.0);"
        "     colors = vp;"
        "}";
const char* fragment_shader =
        "#version 330\n"
        "out vec4 frag_colour;"
        "in vec3 colors;"
        "void main () {"
        "     frag_colour = vec4 (colors, 1.0);"
        "}";


int main(void)
{
    glfwSetErrorCallback(error_callback);
    App::init_glfw();

    glewExperimental = GL_TRUE;
    glewInit();

    auto* my_window = new Window(800, 600, "Hi");
    App::init_glew();

    //what is this?
    glfwSwapInterval(1);

    VBO *vbo = new VBO(sizeof(points), points);
    vbo->bind_buffer();
    VAO * vao = new VAO(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

    //vao->set_vertex(0, 4, GL_FLOAT, GL_FALSE, sizeof(b[0]), (GLvoid*)nullptr);

    //create and compile shaders
    auto *shaderManager = new ShaderManager();
    shaderManager->add_shader(GL_VERTEX_SHADER, &vertex_shader);
    shaderManager->add_shader(GL_FRAGMENT_SHADER, &fragment_shader);
    shaderManager->link_shaders();

    while (my_window->is_open()) {
        // clear color and depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        shaderManager->use_shaders();
        vao->bind_vertex_array();

        // draw triangles
        glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count

        // update other events like input handling
        glfwPollEvents();

        my_window->update_view();
    }

    delete my_window;
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
