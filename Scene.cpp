//
// Created by pavli on 23/10/2022.
//

#include "Scene.h"

#include "SquareColor.h"
#include "axes.h"
#include "Move.h"
#include "Scale.h"
#include "sphere.h"

Drawable *Scene::add_drawable(Drawable *drawable) {
    drawables.push_back(drawable);
    return drawable;
}

void Scene::draw(float *proj, float *view) {
    for (auto &drawable: drawables) {
        drawable->shaderManager->use_shaders();

        glUniformMatrix4fv(0, 1, GL_FALSE, proj);
        glUniformMatrix4fv(1, 1, GL_FALSE, view);

        drawable->render();
    }
}

void Scene::init_spheres() {
    auto constant_shader = new ShaderManager(vertex_shader, fragment_shader);
    constant_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto phong_shader = new ShaderManager(vertex_shader_phong, fragment_shader_phong);
    phong_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-1.0, 0, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(1.0, 0, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(0, -1, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(0, 1, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(constant_shader);

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(constant_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 0.1)));

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(constant_shader)
            ->add_transformation(new Rotate(-90, glm::vec3(0.0, 1.0, 0.0)));
}

void Scene::init() {

    auto first_shader = new ShaderManager(vertex_shader, fragment_shader);
    first_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto second_shader = new ShaderManager(vertex_shader_no_col, fragment_shader);
    second_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto lambert_shader = new ShaderManager(vertex_shader_phong, fragment_shader_lamber);
    lambert_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto phong_shader = new ShaderManager(vertex_shader_phong, fragment_shader_phong);
    phong_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(lambert_shader)
            ->add_transformation(new Move(glm::vec3(-1.0, -1.0, -1)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(sphere), sphere, 2880, 3, true))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-2, -2, -1)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true))
            ->link_shader(first_shader)
            ->add_transformation(new Move(glm::vec3(3.0, 3.0, -20)));

    auto trans = add_drawable(new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true))
            ->link_shader(first_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 1.0), true))
            ->add_transformation(new Move(glm::vec3(3.0, 3.0, -10)))
            ->get_transformation();

    add_drawable(new Drawable(sizeof(data), data, VERTEX_COUNT, VERTEX_SIZE, true))
            ->link_shader(second_shader)
            ->add_transformation(trans)
            ->add_transformation(new Rotate(180, -glm::vec3(0.0, 0.0, 1.0), true))
            ->add_transformation(new Move(glm::vec3(3.0, 0.0, 0.0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(second_shader);

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(first_shader)
            ->add_transformation(new Rotate(90, glm::vec3(0.0, 0.0, 0.1)));

    add_drawable(new Drawable(sizeof(ax), ax, 4, 3, true))
            ->link_shader(first_shader)
            ->add_transformation(new Rotate(-90, glm::vec3(0.0, 1.0, 0.0)));
}
