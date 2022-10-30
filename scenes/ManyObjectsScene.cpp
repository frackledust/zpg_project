//
// Created by pavli on 30/10/2022.
//

#include "ManyObjectsScene.h"
#include "axes.h"
#include "sphere.h"
#include "tree.h"
#include "plain.h"
#include "suzi_smooth.h"
#include "suzi_flat.h"
#include "gift.h"
#include "bushes.h"

void ManyObjectsScene::init() {
    auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs"));
    color_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto lambert_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/lambert.fs"));
    lambert_shader ->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs"));
    phong_shader->link_matrix_name("projection")
            ->link_matrix_name("view")
            ->link_matrix_name("model");

    auto sphere_model = new DataModel(sizeof(sphere), sphere, 2880, 3, true);
    auto tree_model = new DataModel(sizeof(tree), tree, 92814, 3, true);
    auto bush_model = new DataModel(sizeof(bush), bush, 8730, 3, true);
    auto plain_model = new DataModel(sizeof(plain), plain, 6, 3, true);
    auto suzi_smooth_model = new DataModel(sizeof(suziSmooth), suziSmooth, 2904, 3, true);
    auto suzi_flat_model = new DataModel(sizeof(suziFlat), suziFlat, 2904, 3, true);
    auto gift_model = new DataModel(sizeof(gift), gift, 66624, 3, true);

    add_drawable(new Drawable(plain_model))
            ->link_shader(lambert_shader)
            ->add_transformation(new Scale(glm::vec3(8, 8, 8)));

    add_drawable(new Drawable(gift_model))
            ->link_shader(lambert_shader)
            ->add_transformation(new Move(glm::vec3(2, 5, 2)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
            ;

    auto transform = add_drawable(new Drawable(suzi_smooth_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
            ->add_transformation(new Move(glm::vec3(8, 10, -5)))
            ->add_transformation(new Rotate(-45, glm::vec3(0, 1.0, 0.0)))
            ->get_transformation();
;

    add_drawable(new Drawable(suzi_flat_model))
            ->link_shader(phong_shader)
            ->add_transformation(transform)
            ->add_transformation(new Move(glm::vec3(-3, 0, -1)))
;

    add_drawable(new Drawable(sphere_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-1, 1, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sphere_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-1, 5, 0)))
            ->add_transformation(new Scale(glm::vec3(0.3, 0.3, 0.3)));

    srand(time(0));
    for(int i = 0; i < 80; i++){
        int x = rand() % 20 - 10;
        int y = 0;
        int z = rand() % 20 - 10;

        add_drawable(new Drawable(bush_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(x, y, z)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));
    }

    for(int i = 0; i < 20; i++){
        int x = rand() % 10 - 5;
        int y = 0;
        int z = rand() % 10 - 5;
        float size = 0.3 - (rand() % 30) / 100;

        add_drawable(new Drawable(tree_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(x, y, z)))
                ->add_transformation(new Scale(glm::vec3(size, size, size)))
;
    }

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
