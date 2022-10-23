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

int main() {
    App *app = new App(800, 600);
    CallbackController::bind_callbacks();
    app->scene->init();

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
