//
// Created by pavli on 30/09/2022.
//

#include "CallbackController.h"
Camera* CallbackController::camera = nullptr;
Window* CallbackController::app_window = nullptr;

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
    printf("resize %d, %d \n", width, height);

    if(app_window){
        app_window->change_size(width, height);
    }
}

void CallbackController::cursor_callback(GLFWwindow *window, double x, double y) {
    printf("cursor_callback \n");
    if(camera){
        camera->mouse_callback(x, y);
    }
}

void CallbackController::button_callback(GLFWwindow *window, int button, int action, int mode) {
    if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}

void CallbackController::scroll_callback(GLFWwindow *window, double x, double y){
    if(app_window){
            app_window->change_zoom(y);
    }
}

void CallbackController::bind_callbacks() {
    glfwSetErrorCallback(error_callback);
}
