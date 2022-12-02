//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SPHERESPHONGSCENE_H
#define ZPG_PROJECT_SPHERESPHONGSCENE_H


#include "Scene.h"

class SpheresPhongScene : public Scene {

    Scene *clone() override { return new SpheresPhongScene(); };

    void link_lights() override {

        auto point_light = (new PointLight(0, 0, 0))->set_color(1, 1, 1);

        for (auto &shader: shaders) {
            shader->use_shaders();

            shader->set_uniform("lights[0]", point_light);
        }

    }


    void init() override {
        auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vsh", "../shaders/rand_color.fsh"));
        auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/phong.fsh"));

        auto sphere_model = new SphereModel();

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(-1.0, 0, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(1.0, 0, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(0, 1, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        create_axes(color_shader);
    }
};


#endif //ZPG_PROJECT_SPHERESPHONGSCENE_H
