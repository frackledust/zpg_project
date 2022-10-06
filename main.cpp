#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

#include <cstdlib>
#include <iostream>
//
#include "ShaderManager.h"
#include "App.h"
#include "CallbackController.h"

// DATA
//#include "data/SquareColor.h"
#include "data/SquareRotate.h"
#include "Drawable.h"

int main()
{
    App* app = new App(800, 600);
    CallbackController::bind_callbacks();

    glfwSwapInterval(1);

    auto square2 = new Drawable(sizeof(c), c, 4, 4, true, M);
    app->add_drawable(square2);

    auto square = new Drawable(sizeof(b), b, 4, 4, true, M);
    app->add_drawable(square);

    app->shaderManager = new ShaderManager(vertex_shader, fragment_shader, "modelMatrix");

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
