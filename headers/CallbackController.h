//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_CALLBACKCONTROLLER_H
#define ZPG_PROJECT_CALLBACKCONTROLLER_H

#include <cstdlib>
#include <cstdio>
#include "GLFW/glfw3.h"
#include "Camera.h"
#include "Subject.h"

class Camera;

class Window;

class CallbackController : public Subject {
private:
    static void error_callback(int error, const char *description);

    static CallbackController* instance;
    CallbackController();
public:
    static CallbackController* getInstance();

    Window *app_window = nullptr;

    void bind_callbacks();

    void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);

    void window_focus_callback(GLFWwindow *window, int focused);

    void window_iconify_callback(GLFWwindow *window, int iconified);

    void window_size_callback(GLFWwindow *window, int width, int height);

    void cursor_callback(GLFWwindow *window, double x, double y);

    void button_callback(GLFWwindow *window, int button, int action, int mode);

    void scroll_callback(GLFWwindow *window, double x, double y);
};


#endif //ZPG_PROJECT_CALLBACKCONTROLLER_H
