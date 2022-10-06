//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_APP_H
#define ZPG_PROJECT_APP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"

#include <cstdio>
#include <cstdlib>

#include "CallbackController.h"
#include "Window.h"
#include "ShaderManager.h"
#include "Drawable.h"

class App {
private:
    Window *window;
    std::vector<Drawable*> drawables;
public:
    ShaderManager* shaderManager;

    App();
    ~App();
    App(int width, int height);

    void set_window(int width, int height);

    static void init_glfw();
    static void init_glew();
    static void print_info();

    __attribute__((unused)) void add_drawable(Drawable *drawable);

    bool is_open() const;

    void draw_frame();
};


#endif //ZPG_PROJECT_APP_H
