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
#include "axes.h"
#include "Move.h"
#include "Scale.h"

int main() {
    App *app = new App(800, 600);
    CallbackController::bind_callbacks();

    glfwSwapInterval(1);
    auto first_shader = new ShaderManager(vertex_shader, fragment_shader);
    first_shader->link_matrix_name("projection");
    first_shader->link_matrix_name("view");
    first_shader->link_matrix_name("model");

    auto trans = app->add_drawable(new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true))
            ->link_shader(first_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 1.0), true))
            ->add_transformation(new Move(glm::vec3(3.0, 3.0, -10)))
            ->get_transformation();

    app->add_drawable(new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true))
            ->link_shader(first_shader)
            ->add_transformation(trans)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 1.0), true))
            ->add_transformation(new Move(glm::vec3(3.0, 0.0, 0.0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    app->add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(first_shader);

    app->add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(first_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 0.1)));

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;

    exit(EXIT_SUCCESS);
}
