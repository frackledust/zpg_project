//
// Created by pavli on 28/10/2022.
//

#include "SpheresPhongScene.h"
#include "axes.h"
#include "sphere.h"

void SpheresPhongScene::init() {
    auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs"));
    color_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs"));
    phong_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto sphere_model = new DataModel(sizeof(sphere), sphere, 2880, 3, true);

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


    auto ax_model = new DataModel(sizeof(ax), ax, 4, 3, true);

    add_drawable(new Drawable(ax_model))
            ->link_shader(color_shader);

    add_drawable(new Drawable(ax_model))
            ->link_shader(color_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 0.1)));

    add_drawable(new Drawable(ax_model))
            ->link_shader(color_shader)
            ->add_transformation(new Rotate(-90, glm::vec3(0.0, 1.0, 0.0)));
}
