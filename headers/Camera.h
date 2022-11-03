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
#include "Subject.h"

class Window;

class Camera : public Observer, public Subject {
private:
    bool first_mouse = true;
    float last_x = 400;
    float last_y = 300;
    float yaw = -90.0f;
    float pitch = 0;

    glm::vec3 camera_up = glm::vec3(0.0f, 1.0f, 0.0f);
public:
    Camera() = default;

    void update_position(Window *window);

    glm::mat4 get_view() const;

    void mouse_callback(float xpos, float ypos);

    void update(Subject *subject, Event event);

    glm::vec3 camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
};


#endif //ZPG_PROJECT_CAMERA_H
