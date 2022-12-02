//
// Created by pavli on 12/11/2022.
//

#ifndef ZPG_PROJECT_TEXTURESSCENE_H
#define ZPG_PROJECT_TEXTURESSCENE_H

#include "Scene.h"

class TexturesScene : public Scene {

    Scene *clone() override { return new TexturesScene(); };

    void init() override {
        add_cubemap("../textures/skybox/");

        auto texture_shader = add_shader(new ShaderManager("../shaders/textures.vsh", "../shaders/textures.fsh"));
        auto text_light_shader = add_shader(new ShaderManager("../shaders/textures.vsh", "../shaders/text_light.fsh"));
        auto text_mix_shader = add_shader(new ShaderManager("../shaders/textures.vsh", "../shaders/textures_mix.fsh"));
        auto normal_map_shader = add_shader(
                new ShaderManager("../shaders/normal_map.vsh", "../shaders/normal_map.fsh"));
        auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/phong.fsh"));

        auto plain_model = new PlainUVModel();
        auto tree_model = new TreeModel();
        auto monkey_model = new SuziFlatModel();
        auto tree_from_obj = new DataModel("../files/tree/tree.obj");
        auto box_tangent = new DataModel("../files/box/model.obj", TANGENT_DATA);

        add_drawable(new Drawable(box_tangent))
                ->link_texture("../files/box/albedo.png", GL_RGBA)
                ->link_texture("../files/box/normalmap.png", GL_RGB)
                ->link_shader(texture_shader)
                ->add_transformation(new Move(glm::vec3(-0.7, -0.6, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(box_tangent))
                ->link_texture("../files/box/albedo.png", GL_RGBA)
                ->link_texture("../files/box/normalmap.png", GL_RGB)
                ->link_shader(text_light_shader)
                ->add_transformation(new Move(glm::vec3(0, -0.6, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
                ;

        add_drawable(new Drawable(box_tangent))
                ->link_texture("../files/box/albedo.png", GL_RGBA)
                ->link_texture("../files/box/normalmap.png", GL_RGB)
                ->link_shader(normal_map_shader)
                ->add_transformation(new Move(glm::vec3(0.7, -0.6, 0)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)));

        add_drawable(new Drawable(new DataModel("../files/house/model.obj")))
                ->link_texture("../files/house/test.png", GL_RGBA)
                ->link_shader(texture_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, 1)));

        auto target_trans = add_drawable(new Drawable(new DataModel("../files/zombie/zombie.obj")))
                ->link_texture("../files/zombie/zombie.png", GL_RGBA)
                ->link_shader(text_light_shader)
                ->add_transformation(new Move(glm::vec3(1.5, -1, 0)))
                ->add_transformation(new Rotate(-45, glm::vec3(0, 1, 0)))
                ->get_transformation();

        bool move = true;
        auto move_trans = add_drawable(new Drawable(monkey_model))
                ->link_shader(phong_shader)
                ->add_transformation(target_trans)
                ->add_transformation(new Rotate(-45, glm::vec3(0.0, 1.0, 0.0), move))
                ->add_transformation(new Move(glm::vec3(1.0, 2.0, 0.0)))
                ->add_transformation(new Scale(glm::vec3(0.2, 0.2, 0.2)))
                ->get_transformation();

        add_drawable(new Drawable(monkey_model))
                ->link_shader(phong_shader)
                ->add_transformation(move_trans)
                ->add_transformation(new Rotate(-90, glm::vec3(0, 1, 0), move))
                ->add_transformation(new Move(glm::vec3(3.0, 0.0, 0.0)))
                ->add_transformation(new Scale(glm::vec3(0.2, 0.2, 0.2)))
                ;

        add_drawable(new Drawable(monkey_model))
                ->link_shader(phong_shader)
                ->add_transformation(new BezierMove())
                ->add_transformation(new Move(glm::vec3(0, 1, 0)))
                ->add_transformation(new Scale(glm::vec3(0.1, 0.1, 0.1)))
                ;

        add_drawable(new Drawable(monkey_model))
                ->link_shader(phong_shader)
                ->add_transformation(new BezierMove(0.1, glm::mat4x3(glm::vec3(-1, 0, 0),
                                                                glm::vec3(-1, 0, 0),
                                                                glm::vec3(1, 0, 0),
                                                                glm::vec3(1, 0, 0))))
                ->add_transformation(new Scale(glm::vec3(0.1, 0.1, 0.1)))
;


        add_drawable(new Drawable(new DataModel("../files/wall/zed.obj")))
                ->link_texture("../files/wall/bake.png", GL_RGBA)
                ->link_shader(texture_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, -3)))
                ->add_transformation(new Scale(glm::vec3(0.88, 0.65, 0.5)));

        add_drawable(new Drawable(plain_model))
                ->link_texture("../textures/wooden_fence.png", GL_RGBA)
                ->link_texture("../textures/wall.jpg", GL_RGB)
                ->link_shader(text_mix_shader)
                ->add_transformation(new Move(glm::vec3(0, -0.9, 1)))
                ->add_transformation(new Scale(glm::vec3(5, 8, 12)));

        add_drawable(new Drawable(new DataModel("../files/teren/teren.obj")))
                ->link_texture("../textures/grass.jpg", GL_RGB)
                ->link_shader(texture_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, 0)))
                ->add_transformation(new Scale(glm::vec3(15, 15, 15)));

        add_drawable(new Drawable(tree_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(-1.5, -1, 1)))
                ->add_transformation(new Scale(glm::vec3(0.3, 0.3, 0.3)));

        srand(0);
        for (int i = 0; i < 50; i++) {
            double z = -100 + rand() % 100;
            double x = -8 - (rand() % 100);
            add_drawable(new Drawable(tree_from_obj))
                    ->link_texture("../files/tree/tree.png", GL_RGBA)
                    ->link_shader(texture_shader)
                    ->add_transformation(new Move(glm::vec3(x, -1, z)))
                    ->add_transformation(new Scale(glm::vec3(0.2, 0.2, 0.2)));
        }
    }
};


#endif //ZPG_PROJECT_TEXTURESSCENE_H
