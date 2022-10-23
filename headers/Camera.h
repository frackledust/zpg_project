//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_CAMERA_H
#define ZPG_PROJECT_CAMERA_H

#include "Window.h"

#include "glm/vec3.hpp"
#include "glm/fwd.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Window;

class Camera {
private:
    bool firstMouse = true;
    float lastX = 400;
    float lastY = 300;
    float yaw = -90.0f;
    float pitch = 0;

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
public:
    Camera() = default;

    void update_position(Window *window);

    glm::mat4 get_view() const;

    void mouse_callback(float xpos, float ypos) {

        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float x_offset = xpos - lastX;
        float y_offset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

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
        cameraFront = glm::normalize(direction);
    }
};


#endif //ZPG_PROJECT_CAMERA_H
