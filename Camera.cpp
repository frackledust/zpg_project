//
// Created by pavli on 16/10/2022.
//

#include "Camera.h"

glm::mat4 Camera::get_view() const {
    return glm::lookAt(cameraPos, cameraFront, cameraUp);
}

void Camera::update_position(Window *window) {
    const float cameraSpeed = 0.05f;
    if (glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
