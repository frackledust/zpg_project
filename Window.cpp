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

void Window::update_view() const {
    glfwSwapBuffers(window);
}
