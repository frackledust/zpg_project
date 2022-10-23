//
// Created by pavli on 30/09/2022.
//

#include "Window.h"

Window::Window(int width, int height, const char* title) : width(width), height(height){
    this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);

    if (!this->window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(this->window);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glViewport(0, 0, width, height); // window size
}

Window::~Window() {
    glfwDestroyWindow(window);
    printf("Window deleted");
}

bool Window::is_open() const {
    return !glfwWindowShouldClose(this->window);
}

void Window::clear_view() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
}


void Window::update_view() const {
    glfwSwapBuffers(window);
}

void Window::bind_callbacks() const {
    glfwSetKeyCallback(window, CallbackController::key_callback);

    glfwSetCursorPosCallback(window, CallbackController::cursor_callback);

    glfwSetMouseButtonCallback(window, CallbackController::button_callback);

    glfwSetWindowFocusCallback(window, CallbackController::window_focus_callback);

    glfwSetWindowIconifyCallback(window, CallbackController::window_iconify_callback);

    glfwSetWindowSizeCallback(window, CallbackController::window_size_callback);

    glfwSetScrollCallback(window, CallbackController::scroll_callback);
}

void Window::change_size(int width, int height){
    glViewport(0, 0, width, height);
    this->width = width;
    this->height = height;
}

void Window::change_zoom(double y_offset){
    zoom -= (float)y_offset;
    if (zoom < 1.0f)
        zoom = 1.0f;
//    if (zoom > 45.0f)
//        zoom = 45.0f;
}

glm::mat4 Window::get_projection() const {
    return glm::perspective(glm::radians(zoom), (float) width/ (float) height, 0.1f, 100.0f);
}

