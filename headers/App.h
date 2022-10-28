//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_APP_H
#define ZPG_PROJECT_APP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cstdio>
#include <cstdlib>

#include "CallbackController.h"
#include "Window.h"
#include "ShaderManager.h"
#include "Drawable.h"
#include "Camera.h"
#include "Scene.h"

class App {
private:
    std::vector<Drawable *> drawables;
public:
    App(int width, int height);

    ~App();

    static void print_info();

    __attribute__((unused)) Drawable *add_drawable(Drawable *drawable);

    bool is_open() const;

    void draw_frame() const;

    Scene *scene;
    Camera *camera;
    Window *window;
};


#endif //ZPG_PROJECT_APP_H
