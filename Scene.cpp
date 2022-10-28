//
// Created by pavli on 23/10/2022.
//

#include "Scene.h"

#include "SquareColor.h"
#include "axes.h"
#include "Move.h"
#include "Scale.h"
#include "sphere.h"

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
    }
}

void Scene::draw(const glm::mat4 &proj, const glm::mat4 &view) {
    for (auto &drawable: drawables) {
        drawable->shader_manager->use_shaders();

        drawable->render();
    }
}

void Scene::init_spheres_phong() {
    auto color_shader = new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs");
    color_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto phong_shader = new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs");
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

void Scene::init_spheres_different() {
    auto constant_shader = add_shader(new ShaderManager("../shaders/const.vs", "../shaders/const.fs"));
    constant_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs"));
    color_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto lambert_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/lambert.fs"));
    lambert_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");


    auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs"));
    phong_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto blinn_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/blinn.fs"));
    blinn_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto sphere_model = new DataModel(sizeof(sphere), sphere, 2880, 3, true);

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
