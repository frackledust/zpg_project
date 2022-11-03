//
// Created by pavli on 30/09/2022.
//

#include "CallbackController.h"

CallbackController *CallbackController::instance = nullptr;

CallbackController *CallbackController::get_instance() {
    if (instance == nullptr) {
        instance = new CallbackController();
    }
    return instance;
}

void CallbackController::error_callback(int error, const char *description) {
    fputs(description, stderr);
}

void CallbackController::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void CallbackController::window_focus_callback(GLFWwindow *window, int focused) {
    printf("window_focus_callback \n");
}

void CallbackController::window_iconify_callback(GLFWwindow *window, int iconified) {
    printf("window_iconify_callback \n");
}

void CallbackController::window_size_callback(GLFWwindow *window, int width, int height) {
    data[0] = width;
    data[1] = height;
    notify_observers(WINDOW_SIZE_CHANGE);
}

void CallbackController::cursor_callback(GLFWwindow *window, double x, double y) {
    data[0] = x;
    data[1] = y;
    notify_observers(VIEW_UPDATE);
}

void CallbackController::button_callback(GLFWwindow *window, int button, int action, int mode) {
    if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void CallbackController::scroll_callback(GLFWwindow *window, double x, double y) {
    data[0] = x;
    data[1] = y;
    notify_observers(ZOOM_UPDATE);
}

void CallbackController::bind_callbacks() {
    glfwSetErrorCallback(error_callback);
}

const double *CallbackController::get_last_data() {
    return data;
}
