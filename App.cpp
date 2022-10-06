//
// Created by pavli on 30/09/2022.
//

#include "App.h"

App::App() {
    CallbackController::bind_callbacks();
    App::init_glfw();
}

App::~App() {
    delete window;
    glfwTerminate();
}


App::App(int width, int height) : App() {
    this->set_window(width, height);

    init_glew();
}

void App::set_window(int width, int height) {
    window = new Window(width, height, "Hi");
}


void App::init_glfw() {

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

}

void App::init_glew() {
    glewExperimental = GL_TRUE;
    glewInit();
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

    shaderManager->use_shaders();

    for(auto& drawable : drawables){
        drawable->render();
    }

    glfwPollEvents();
    window->update_view();
}

bool App::is_open() const {
    return window->is_open();
}

void App::add_drawable(Drawable* drawable) {
    drawables.push_back(drawable);
}







