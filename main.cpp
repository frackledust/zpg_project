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

    //what is this?
    glfwSwapInterval(1);

    //data layer
    auto square = new Drawable(sizeof(b), b, 4, 4, true, M);
    app->drawables.push_back(square);

    //shaders
    auto *shaderManager = new ShaderManager();
    shaderManager->add_shader(GL_VERTEX_SHADER, &vertex_shader);
    shaderManager->add_shader(GL_FRAGMENT_SHADER, &fragment_shader);
    shaderManager->link_shaders();
    std::cout << shaderManager->link_matrix("modelMatrix") << "\n";


    app->shaderManager = shaderManager;
    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
