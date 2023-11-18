//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SPHERESDIFFSCENE_H
#define ZPG_PROJECT_SPHERESDIFFSCENE_H


#include "Scene.h"

class SpheresDiffScene : public Scene {
    Scene *clone() override { return new SpheresDiffScene(); };

    void link_lights() override {

        auto point_light = (new PointLight(0, 0, 0))->set_color(0.385, 0.647, 0.812);

        for (auto &shader: shaders) {
            shader->use_shaders();

            shader->set_uniform("lights[0]", point_light);
        }

    }

    void init() override {

        auto constant_shader = add_shader(std::make_shared<ShaderManager>("../shaders/const.vsh", "../shaders/const.fsh"));
        auto color_shader = add_shader(std::make_shared<ShaderManager>("../shaders/rand_color.vsh", "../shaders/rand_color.fsh"));
        auto lambert_shader = add_shader(std::make_shared<ShaderManager>("../shaders/phong.vsh", "../shaders/lambert.fsh"));
        auto phong_shader = add_shader(std::make_shared<ShaderManager>("../shaders/phong.vsh", "../shaders/phong.fsh"));
        auto blinn_shader = add_shader(std::make_shared<ShaderManager>("../shaders/phong.vsh", "../shaders/blinn.fsh"));


        auto sphere_model = make_shared<SphereModel>();

        add_drawable(new Drawable(sphere_model))
                ->link_shader(constant_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(-1.0, 0, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(lambert_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(1.0, 0, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(0, -1, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(blinn_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(0, 1, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        create_axes(color_shader);
    }
};


#endif //ZPG_PROJECT_SPHERESDIFFSCENE_H
