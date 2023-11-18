//
// Created by pavli on 30/10/2022.
//

#ifndef ZPG_PROJECT_MANYOBJECTSSCENE_H
#define ZPG_PROJECT_MANYOBJECTSSCENE_H

#include "Scene.h"

class ManyObjectsScene : public Scene {

    Scene *clone() override { return new ManyObjectsScene(); };

    void init() override {
        auto color_shader = add_shader(std::make_shared<ShaderManager>("../shaders/rand_color.vsh", "../shaders/rand_color.fsh"));
        auto lambert_shader = add_shader(std::make_shared<ShaderManager>("../shaders/phong.vsh", "../shaders/lambert.fsh"));
        auto phong_shader = add_shader(std::make_shared<ShaderManager>("../shaders/phong.vsh", "../shaders/phong.fsh"));

        auto sphere_model = std::make_shared<SphereModel>();
        auto tree_model = std::make_shared<TreeModel>();
        auto bush_model = std::make_shared<BushModel>();
        auto plain_model = std::make_shared<PlainModel>();
        auto suzi_smooth_model = std::make_shared<SuziSmoothModel>();
        auto suzi_flat_model = std::make_shared<SuziFlatModel>();
        auto gift_model = std::make_shared<GiftModel>();

        add_drawable(new Drawable(plain_model))
                ->link_shader(lambert_shader)
                ->add_transformation(make_shared<Scale>(glm::vec3(15, 15, 15)));

        add_drawable(new Drawable(gift_model))
                ->link_shader(lambert_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(2, 5, 2)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        auto transform = add_drawable(new Drawable(suzi_smooth_model))
                ->link_shader(phong_shader)
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)))
                ->add_transformation(make_shared<Move>(glm::vec3(8, 10, -5)))
                ->add_transformation(make_shared<Rotate>(-45, glm::vec3(0, 1.0, 0.0)))
                ->get_transformation();

        add_drawable(new Drawable(suzi_flat_model))
                ->link_shader(phong_shader)
                ->add_transformation(transform)
                ->add_transformation(make_shared<Move>(glm::vec3(-3, 0, -1)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(-1, 1, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(sphere_model))
                ->link_shader(phong_shader)
                ->add_transformation(make_shared<Move>(glm::vec3(-1, 5, 0)))
                ->add_transformation(make_shared<Scale>(glm::vec3(0.3, 0.3, 0.3)));

        srand(time(nullptr));
        for (int i = 0; i < 80; i++) {
            int x = rand() % 20 - 10;
            int y = (rand() % 30 + 10) / 10 + 5;
            int z = rand() % 20 - 10;

            add_drawable(new Drawable(sphere_model))
                    ->link_shader(phong_shader)
                    ->add_transformation(make_shared<Move>(glm::vec3(x, y, z)))
                    ->add_transformation(make_shared<Scale>(glm::vec3(0.3, 0.3, 0.3)));
        }

        for (int i = 0; i < 20; i++) {
            int x = rand() % 20 - 10;
            int y = 0;
            int z = rand() % 20 - 10;
            double size = ((float)((rand() % 90) + 10)) / 100 ;

            add_drawable(new Drawable(tree_model))
                    ->link_shader(phong_shader)
                    ->add_transformation(make_shared<Move>(glm::vec3(x, y, z)))
                    ->add_transformation(make_shared<Scale>(glm::vec3(size, size, size)));
        }

        for (int i = 0; i < 20; i++) {
            int x = rand() % 20 - 10;
            int y = 0;
            int z = rand() % 20 - 10;
            double size = 0.5 ;

            add_drawable(new Drawable(bush_model))
                    ->link_shader(phong_shader)
                    ->add_transformation(make_shared<Move>(glm::vec3(x, y, z)))
                    ->add_transformation(make_shared<Scale>(glm::vec3(size, size, size)));
        }

    }
};


#endif //ZPG_PROJECT_MANYOBJECTSSCENE_H
