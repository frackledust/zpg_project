//
// Created by pavli on 23/10/2022.
//

#include "Scene.h"

ShaderManager *Scene::add_shader(ShaderManager *shader) {
    shaders.push_back(shader);
    return shader;
}

Drawable *Scene::add_drawable(Drawable *drawable) {
    drawables.push_back(drawable);
    return drawable;
}

void Scene::link_shaders(Camera *camera, Window *window) {
    auto proj = window->get_projection();
    auto view = camera->get_view();



    for (auto &shader: shaders) {
        camera->registerObserver(shader);
        window->registerObserver(shader);

        shader->use_shaders();

        if(light){
            shader->set_uniform("projection", proj);
            shader->set_uniform("view", view);
            shader->set_uniform("light", light->get_position());
        }
    }
}

void Scene::draw() {
    for (auto &drawable: drawables) {
        drawable->render();
    }
}

void Scene::link_light(Light *l) {
    this->light = l;
}


