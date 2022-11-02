//
// Created by pavli on 23/10/2022.
//
#ifndef ZPG_PROJECT_SCENE_H
#define ZPG_PROJECT_SCENE_H


#include "Drawable.h"
#include "Camera.h"

#include "models/SphereModel.h"
#include "models/TreeModel.h"
#include "models/BushModel.h"
#include "models/PlainModel.h"
#include "models/SuziSmoothModel.h"
#include "models/SuziFlatModel.h"
#include "models/GiftModel.h"


#include "Move.h"
#include "Scale.h"
#include "Rotate.h"
#include "Light.h"

class Scene {
private:
    Light* light = nullptr;
    std::vector<ShaderManager *> shaders;
    std::vector<Drawable *> drawables;

protected:
    void create_axes(ShaderManager *shader);

public:
    virtual ~Scene() = default;
    ShaderManager *add_shader(ShaderManager *shader);

    Drawable *add_drawable(Drawable *drawable);

    void draw();

    virtual void init() {};

    void link_shaders(Camera *camera, Window *window);

    void link_light(Light* l);

    virtual Scene* clone() = 0;
};


#endif //ZPG_PROJECT_SCENE_H
