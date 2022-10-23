//
// Created by pavli on 30/09/2022.
//

#include "Window.h"

Window::Window(int width, int height, const char *title) : width(width), height(height) {
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
    auto pos_callback = [](GLFWwindow *w, double x, double y) {CallbackController::getInstance()->cursor_callback(w, x, y);};
    glfwSetCursorPosCallback(window, pos_callback);

    auto button_callback = [](GLFWwindow *w, int button, int action, int mode) {CallbackController::getInstance()->button_callback(w, button, action, mode);};
    glfwSetMouseButtonCallback(window, button_callback);

    auto focus_callback = [](GLFWwindow *w, int focused) {CallbackController::getInstance()->window_focus_callback(w, focused);};
    glfwSetWindowFocusCallback(window, focus_callback);

    auto iconify_callback = [](GLFWwindow *w, int iconified){CallbackController::getInstance()->window_iconify_callback(w, iconified);};
    glfwSetWindowIconifyCallback(window, iconify_callback);

    auto size_callback = [](GLFWwindow *w, int w_width, int w_height){CallbackController::getInstance()->window_size_callback(w, w_width, w_height);};
    glfwSetWindowSizeCallback(window, size_callback);

    auto scroll_callback = [](GLFWwindow *w, double x, double y){CallbackController::getInstance()->scroll_callback(w, x, y);};
    glfwSetScrollCallback(window, scroll_callback);
}

void Window::change_size(int width, int height) {
    glViewport(0, 0, width, height);
    this->width = width;
    this->height = height;
}

void Window::change_zoom(double y_offset) {
    zoom -= (float) y_offset;
    if (zoom < 1.0f)
        zoom = 1.0f;
//    if (zoom > 45.0f)
//        zoom = 45.0f;
}

glm::mat4 Window::get_projection() const {
    return glm::perspective(glm::radians(zoom), (float) width / (float) height, 0.1f, 100.0f);
}

