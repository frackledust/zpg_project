//
// Created by pavli on 23/10/2022.
//

#include "Scene.h"
#include "data/axes.h"

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

        shader->set_uniform("projection", proj);
        shader->set_uniform("view", view);

        shader->set_uniform("lights[0]", Light(POINT, 0, 0, 0));
        shader->set_uniform("lights[1]", Light(DIR, 0, 1, 0));
        shader->set_uniform("spotlight", Light(SPOT, camera->camera_pos, camera->camera_front));
    }
}

void Scene::draw() {
    for (auto &drawable: drawables) {
        drawable->render();
    }
}

void Scene::create_axes(ShaderManager *shader) {
    auto ax_model = new DataModel(sizeof(ax), ax, 4, 3, true);

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader);

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 0.1)));

    add_drawable(new Drawable(ax_model))
            ->link_shader(shader)
            ->add_transformation(new Rotate(-90, glm::vec3(0.0, 1.0, 0.0)));
}


