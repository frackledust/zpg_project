//
// Created by pavli on 30/09/2022.
//

#include "App.h"

App::~App() {
    delete window;
    glfwTerminate();
}


App::App(int width, int height) {
    CallbackController::getInstance()->bind_callbacks();

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    window = new Window(width, height, "Hi");
    window->bind_callbacks();

    camera = new Camera();
    scene = new Scene();
    glewExperimental = GL_TRUE;
    glewInit();

    glfwSwapInterval(1);

    auto proj = window->get_projection();
    auto view = camera->get_view();
    scene->init_spheres_different();
    scene->link_shaders(camera, window);

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

void App::draw_frame() const {
    window->clear_view();

    camera->update_position(window);

    auto proj = window->get_projection();
    auto view = camera->get_view();
    scene->draw(proj, view);

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







