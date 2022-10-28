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
    auto pos_callback = [](GLFWwindow *w, double x, double y) {
        CallbackController::get_instance()->cursor_callback(w, x, y);
    };
    glfwSetCursorPosCallback(window, pos_callback);

    auto key_callback = [](GLFWwindow *w, int key, int scancode, int action, int mods) {
        CallbackController::get_instance()->key_callback(w, key, scancode, action, mods);
    };
    glfwSetKeyCallback(window, key_callback);

    auto button_callback = [](GLFWwindow *w, int button, int action, int mode) {
        CallbackController::get_instance()->button_callback(w, button, action, mode);
    };
    glfwSetMouseButtonCallback(window, button_callback);

    auto focus_callback = [](GLFWwindow *w, int focused) {
        CallbackController::get_instance()->window_focus_callback(w, focused);
    };
    glfwSetWindowFocusCallback(window, focus_callback);

    auto iconify_callback = [](GLFWwindow *w, int iconified) {
        CallbackController::get_instance()->window_iconify_callback(w, iconified);
    };
    glfwSetWindowIconifyCallback(window, iconify_callback);

    auto size_callback = [](GLFWwindow *w, int w_width, int w_height) {
        CallbackController::get_instance()->window_size_callback(w, w_width, w_height);
    };
    glfwSetWindowSizeCallback(window, size_callback);

    auto scroll_callback = [](GLFWwindow *w, double x, double y) {
        CallbackController::get_instance()->scroll_callback(w, x, y);
    };
    glfwSetScrollCallback(window, scroll_callback);
}

void Window::change_size(int w, int h) {
    this->width = w;
    this->height = h;
    glViewport(0, 0, w, h);
    notify_observers("projection", get_projection());
}

void Window::change_zoom(double y_offset) {
    zoom -= (float) y_offset;
    if (zoom < 1.0f)
        zoom = 1.0f;
//    if (zoom > 45.0f)
//        zoom = 45.0f;

    notify_observers("projection", get_projection());
}

glm::mat4 Window::get_projection() const {
    return glm::perspective(glm::radians(zoom), (float) width / (float) height, 0.1f, 100.0f);
}

bool Window::is_pressed(int key) const {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

