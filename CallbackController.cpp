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
}

void CallbackController::window_focus_callback(GLFWwindow *window, int focused) {
    printf("window_focus_callback \n");
}

void CallbackController::window_iconify_callback(GLFWwindow *window, int iconified) {
    printf("window_iconify_callback \n");
    notify_observers(WINDOW_ICONIFY);
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

bool CallbackController::check_window_camera() {
    if (my_window != nullptr && camera != nullptr) return false;

    for (auto o: observers) {
        if (my_window == nullptr) {
            my_window = dynamic_cast<Window *>(o);
        }
        if (camera == nullptr) {
            camera = dynamic_cast<Camera *>(o);
        }
    }

    return my_window == nullptr || camera == nullptr;
};

void CallbackController::calculate_position(double xpos, double ypos) {
    GLbyte color[4];
    GLfloat depth;
    GLuint index;

    if (check_window_camera()) return;

    glm::vec<4, float> viewPort = my_window->get_viewport();

    ypos = viewPort[3] - ypos;
    glReadPixels(xpos, ypos, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
    glReadPixels(xpos, ypos, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
    glReadPixels(xpos, ypos, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

    printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
           (int) xpos, (int) ypos, color[0], color[1], color[2], color[3], depth, index);

    glm::vec3 screen_pos = glm::vec3(xpos, ypos, depth);
    glm::mat4 view = camera->get_view();
    glm::mat4 projection = my_window->get_projection();

    glm::vec3 pos = glm::unProject(screen_pos, view, projection, viewPort); // screen pos into object pos

    printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);
    data[0] = pos.x;
    data[1] = pos.y;
    data[2] = pos.z;
    data[3] = index;
    notify_observers(CLICK_UPDATE);
}

void CallbackController::button_callback(GLFWwindow *window, int button, int action, int mode) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        calculate_position(x, y);
    }
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
