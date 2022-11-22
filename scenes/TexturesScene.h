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
        auto phong_shader = add_shader(new ShaderManager("../shaders/phong.vsh", "../shaders/phong.fsh"));
        auto plain_model = new PlainUVModel();
        auto tree_model = new TreeModel();

        add_drawable(new Drawable(new DataModel("../data/model.obj")))
                ->link_texture("../textures/model.png", GL_RGBA)
                ->link_shader(text_light_shader)
                ;

        add_drawable(new Drawable(plain_model))
                ->link_texture("../textures/wooden_fence.png", GL_RGBA)
                ->link_shader(text_light_shader)
                ->add_transformation(new Rotate(90, glm::vec3(1, 0, 0)))
                ;

        add_drawable(new Drawable(plain_model))
                ->link_texture("../textures/grass.jpg", GL_RGB)
                ->link_shader(texture_shader)
                ->add_transformation(new Move(glm::vec3(0, -1, 1)))
                ->add_transformation(new Scale(glm::vec3(15, 15, 15)))
                ;

        add_drawable(new Drawable(tree_model))
                ->link_shader(phong_shader)
                ->add_transformation(new Move(glm::vec3(-1, -1, 1)))
                ->add_transformation(new Scale(glm::vec3(0.5, 0.5, 0.5)))
                ;
    }
};


#endif //ZPG_PROJECT_TEXTURESSCENE_H
