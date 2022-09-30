//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_APP_H
#define ZPG_PROJECT_APP_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstdlib>

#include "CallbackController.h"
#include "Window.h"
#include "ShaderManager.h"
#include "VAO.h"

class App {
public:
    Window *window;

    App();
    ~App();
    App(int width, int height);

    void set_window(int width, int height);

    static void init_glfw();
    static void init_glew();
    static void print_info();

    void draw_frame(ShaderManager* shaderManager, VAO* vao);

    bool is_open();
};


#endif //ZPG_PROJECT_APP_H
