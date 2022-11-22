//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_APP_H
#define ZPG_PROJECT_APP_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <cstdio>
#include <cstdlib>

#include "CallbackController.h"
#include "SceneFactory.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "Plotter.h"

class App {
private:
    Window *window;
    Camera *camera;
    Scene *scene;

    Plotter* plotter;
public:
    App(int width, int height);

    ~App();

    static void print_info();

    [[nodiscard]] bool is_open() const;

    void draw_frame() const;
};


#endif //ZPG_PROJECT_APP_H
