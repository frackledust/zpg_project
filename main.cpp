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
//#include "SquareColor.h"
//#include "SquareRotate.h"
#include "TwoInOne.h"
#include "Drawable.h"

int main()
{
    App* app = new App(800, 600);
    CallbackController::bind_callbacks();

    glfwSwapInterval(1);
    auto shader = new ShaderManager(vertex_shader, fragment_shader);
    shader->link_matrix_name("modelMatrix");

    auto shader2 = new ShaderManager(vertex_shader2, fragment_shader2);
    shader2->link_matrix_name("modelMatrix");

    auto square = new Drawable(sizeof(data1), data1, 5, 4, true, M);
    square->link_shader(shader);
    app->add_drawable(square);

    auto triangle = new Drawable(sizeof(data2), data2, 3, 4, false, M2);
    triangle->link_shader(shader2);
    app->add_drawable(triangle);

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
