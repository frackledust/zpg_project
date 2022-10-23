//
// Created by pavli on 30/09/2022.
//

#include "App.h"

App::~App() {
    delete window;
    glfwTerminate();
}


App::App(int width, int height) {
    CallbackController::bind_callbacks();

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    this->set_window(width, height);

    glewExperimental = GL_TRUE;
    glewInit();
}

void App::set_window(int width, int height) {
    window = new Window(width, height, "Hi");

    window->bind_callbacks();

    camera = new Camera();
}

void App::print_info() {
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

void App::draw_frame() {
    window->clear_view();

    camera->update_position(window);

    for (auto &drawable: drawables) {
        drawable->shaderManager->use_shaders();

        auto view = camera->get_view();
        auto proj = window->get_projection();
        glUniformMatrix4fv(0, 1, GL_FALSE, &proj[0][0]);
        glUniformMatrix4fv(1, 1, GL_FALSE, &view[0][0]);

        drawable->render();
    }

    glfwPollEvents();
    window->update_view();
}

bool App::is_open() const {
    return window->is_open();
}

Drawable *App::add_drawable(Drawable *drawable) {
    drawables.push_back(drawable);
    return drawable;
}







