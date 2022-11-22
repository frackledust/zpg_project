//
// Created by pavli on 22/11/2022.
//

#ifndef ZPG_PROJECT_PLOTTER_H
#define ZPG_PROJECT_PLOTTER_H

#include "Observer.h"
#include "Scene.h"
#include "DataModel.h"

#include "GLFW/glfw3.h"

class Scene;

class Plotter : public Observer {
    Scene* scene;
    Camera* camera;
    Window* window;

    ShaderManager* shader;
    DataModel* model;

    void update(Subject* subject, Event event);

public:
    Plotter(Scene* scene);
};


#endif //ZPG_PROJECT_PLOTTER_H
