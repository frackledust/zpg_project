//
// Created by pavli on 16/10/2022.
//

#include "Camera.h"

glm::mat4 Camera::get_view() const {
    return glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);
}

void Camera::update_position(Window *window) {
    const float cameraSpeed = 0.05f;
    bool updated = false;
    if (window->is_pressed(GLFW_KEY_W)){
        camera_pos += cameraSpeed * camera_front;
        updated = true;
    }
    if (window->is_pressed(GLFW_KEY_S)){
        camera_pos -= cameraSpeed * camera_front;
        updated = true;
    }
    if (window->is_pressed(GLFW_KEY_A)){
        camera_pos -= glm::normalize(glm::cross(camera_front, camera_up)) * cameraSpeed;
        updated = true;
    }
    if (window->is_pressed(GLFW_KEY_D)){
        camera_pos += glm::normalize(glm::cross(camera_front, camera_up)) * cameraSpeed;
        updated = true;
    }
    if (window->is_pressed(GLFW_KEY_E)){
        camera_pos -= cameraSpeed * camera_up;
        updated = true;
    }
    if (window->is_pressed(GLFW_KEY_Q)){
        camera_pos += cameraSpeed * camera_up;
        updated = true;
    }

    if(updated){
        notify_observers(Event::VIEW_UPDATE);
    }
}

void Camera::update(Subject* subject, Event event) {
    if(event == Event::VIEW_UPDATE){
        auto data = CallbackController::get_instance()->get_last_data();
        mouse_callback((float) data[0], (float) data[1]);
    }
}

void Camera::mouse_callback(float xpos, float ypos) {

    if (first_mouse) {
        last_x = xpos;
        last_y = ypos;
        first_mouse = false;
    }

    float x_offset = xpos - last_x;
    float y_offset = last_y - ypos;
    last_x = xpos;
    last_y = ypos;

    float sensitivity = 0.1f;
    x_offset *= sensitivity;
    y_offset *= sensitivity;

    yaw += x_offset;
    pitch += y_offset;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camera_front = glm::normalize(direction);

    notify_observers(Event::VIEW_UPDATE);
}

glm::vec3 Camera::get_position() {
    return camera_pos;
}

glm::vec3 Camera::get_direction() {
    return camera_front;
}
