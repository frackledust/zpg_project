//
// Created by pavli on 28/10/2022.
//

#include "SpheresPhongScene.h"

void SpheresPhongScene::init() {
    auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs"));
    auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs"));

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
