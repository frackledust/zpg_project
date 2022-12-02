//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_WINDOW_H
#define ZPG_PROJECT_WINDOW_H

#include <cstdio>
#include <cstdlib>
#include "GLFW/glfw3.h"
#include "CallbackController.h"
#include "Subject.h"

#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Window : public Subject, public Observer {
    GLFWwindow *window;

    int width;
    int height;

    float zoom = 45;

    bool iconified = false;
public:
    Window(int width, int height, const char *title);

    ~Window();

    bool is_open() const;

    void clear_view();

    void update_view() const;

    bool is_pressed(int key) const;

    void bind_callbacks() const;

    glm::mat4 get_projection() const;

    void change_zoom(double y_offset);

    void change_size(int width, int height);

    void update(Subject *subject, Event event);

    glm::vec4 get_viewport() const;
};


#endif //ZPG_PROJECT_WINDOW_H
