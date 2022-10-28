//
// Created by pavli on 23/10/2022.
//
#ifndef ZPG_PROJECT_SCENE_H
#define ZPG_PROJECT_SCENE_H


#include "Drawable.h"
#include "Camera.h"
#include "Move.h"
#include "Scale.h"

class Scene {
private:
    std::vector<ShaderManager *> shaders;
    std::vector<Drawable *> drawables;

public:
    ShaderManager *add_shader(ShaderManager *shader);

    Drawable *add_drawable(Drawable *drawable);

    void draw();

    virtual void init() {};

    void link_shaders(Camera *camera, Window *window);

    virtual Scene* clone() = 0;
};


#endif //ZPG_PROJECT_SCENE_H
