//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SPHERESDIFFSCENE_H
#define ZPG_PROJECT_SPHERESDIFFSCENE_H


#include "Scene.h"

class SpheresDiffScene : public Scene {
    Scene *clone() override { return new SpheresDiffScene(); };

    void init() override {

        auto constant_shader = add_shader(new ShaderManager("../shaders/const.vsh", "../shaders/const.fsh"));
        auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vsh", "../shaders/rand_color.fsh"));
        auto lambert_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/lambert.fsh"));
        auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/phong.fsh"));
        auto blinn_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/blinn.fsh"));


        auto sphere_model = new SphereModel();

        add_drawable(new Drawable(sphere_model))
                ->link_shader(constant_shader)
                ->add_transformation(new Move(glm::vec3(-1.0, 0, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(lambert_shader)
                ->add_transformation(new Move(glm::vec3(1.0, 0, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(blinn_shader)
                ->add_transformation(new Move(glm::vec3(0, 1, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        create_axes(color_shader);
    }
};


#endif //ZPG_PROJECT_SPHERESDIFFSCENE_H
