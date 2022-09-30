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

    glViewport(0, 0, width, height);
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
}


void Window::update_view() const {
    glfwSwapBuffers(window);
}

void Window::bind_callbacks() {
    glfwSetKeyCallback(window, CallbackController::key_callback);

    glfwSetCursorPosCallback(window, CallbackController::cursor_callback);

    glfwSetMouseButtonCallback(window, CallbackController::button_callback);

    glfwSetWindowFocusCallback(window, CallbackController::window_focus_callback);

    glfwSetWindowIconifyCallback(window, CallbackController::window_iconify_callback);

    glfwSetWindowSizeCallback(window, CallbackController::window_size_callback);

}

