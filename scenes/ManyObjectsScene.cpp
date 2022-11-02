//
// Created by pavli on 30/10/2022.
//

#include "ManyObjectsScene.h"

void ManyObjectsScene::init() {
    auto color_shader = add_shader(new ShaderManager("../shaders/rand_color.vs", "../shaders/rand_color.fs"));
    auto lambert_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/lambert.fs"));
    auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vs", "../shaders/phong.fs"));

    auto sphere_model = new SphereModel();
    auto tree_model = new TreeModel();
    auto bush_model = new BushModel();
    auto plain_model = new PlainModel();
    auto suzi_smooth_model = new SuziSmoothModel();
    auto suzi_flat_model = new SuziFlatModel();
    auto gift_model = new GiftModel();

    add_drawable(new Drawable(plain_model))
            ->link_shader(lambert_shader)
            ->add_transformation(new Scale(glm::vec3(8, 8, 8)));

    add_drawable(new Drawable(gift_model))
            ->link_shader(lambert_shader)
            ->add_transformation(new Move(glm::vec3(2, 5, 2)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    auto transform = add_drawable(new Drawable(suzi_smooth_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
            ->add_transformation(new Move(glm::vec3(8, 10, -5)))
            ->add_transformation(new Rotate(-45, glm::vec3(0, 1.0, 0.0)))
            ->get_transformation();

    add_drawable(new Drawable(suzi_flat_model))
            ->link_shader(phong_shader)
            ->add_transformation(transform)
            ->add_transformation(new Move(glm::vec3(-3, 0, -1)));

    add_drawable(new Drawable(sphere_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-1, 1, 0)))
            ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

    add_drawable(new Drawable(sphere_model))
            ->link_shader(phong_shader)
            ->add_transformation(new Move(glm::vec3(-1, 5, 0)))
            ->add_transformation(new Scale(glm::vec3(0.3, 0.3, 0.3)));

    srand(time(nullptr));
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
        double size = 0.3 - (rand() % 30) / 100;

        add_drawable(new Drawable(tree_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(x, y, z)))
                ->add_transformation(new Scale(glm::vec3(size, size, size)));
    }

    create_axes(color_shader);
}
