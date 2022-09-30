//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_CALLBACKCONTROLLER_H
#define ZPG_PROJECT_CALLBACKCONTROLLER_H

#include <cstdlib>
#include <cstdio>
#include "GLFW/glfw3.h"

class CallbackController {
private:
    static void error_callback(int error, const char* description);
public:
    static void bind_callbacks();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void window_focus_callback(GLFWwindow* window, int focused);
    static void window_iconify_callback(GLFWwindow* window, int iconified);
    static void window_size_callback(GLFWwindow* window, int width, int height);
    static void cursor_callback(GLFWwindow *window, double x, double y);
    static void button_callback(GLFWwindow* window, int button, int action, int mode);

};


#endif //ZPG_PROJECT_CALLBACKCONTROLLER_H
