//
// Created by pavli on 22/11/2022.
//

#ifndef ZPG_PROJECT_PLOTTER_H
#define ZPG_PROJECT_PLOTTER_H

#include "Observer.h"
#include "Scene.h"
#include "DataModel.h"

class Scene;

class Plotter : public Observer {
    Scene* scene;
    Camera* camera;
    Window* window;

    std::shared_ptr<ShaderManager> shader;
    std::shared_ptr<DataModel> model;

    void update(Subject* subject, Event event) override;

public:
    explicit Plotter(Scene* scene);
};


#endif //ZPG_PROJECT_PLOTTER_H
