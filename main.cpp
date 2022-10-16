#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4

#include <cstdlib>
#include <iostream>
//
#include "Drawable.h"
#include "ShaderManager.h"
#include "App.h"
#include "CallbackController.h"

// DATA
#include "SquareColor.h"

int main()
{
    App* app = new App(800, 600);
    CallbackController::bind_callbacks();

    glfwSwapInterval(1);
    auto first_shader = new ShaderManager(vertex_shader, fragment_shader);
    int projection = first_shader->link_matrix_name("projection");
    int view = first_shader->link_matrix_name("view");
    int model = first_shader->link_matrix_name("model");

    auto shape_one = new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true);
    shape_one->link_shader(first_shader);
    app->add_drawable(shape_one);

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;

    exit(EXIT_SUCCESS);
}
