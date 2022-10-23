//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_CAMERA_H
#define ZPG_PROJECT_CAMERA_H

#include "Window.h"

#include "glm/vec3.hpp"
#include "glm/fwd.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Observer.h"
class Window;

class Camera : public Observer {
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

    void update(float x, float y);
    void mouse_callback(float xpos, float ypos);

};


#endif //ZPG_PROJECT_CAMERA_H
