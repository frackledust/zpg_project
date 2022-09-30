//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_WINDOW_H
#define ZPG_PROJECT_WINDOW_H

#include <cstdio>
#include <cstdlib>
#include "GLFW/glfw3.h"
#include "CallbackController.h"

class Window {
    GLFWwindow* window;
    int width;
    int height;
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool is_open() const;
    void clear_view();
    void update_view() const;

    void bind_callbacks();
};


#endif //ZPG_PROJECT_WINDOW_H
