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
#include "models/PlainUVModel.h"
#include "models/SuziSmoothModel.h"
#include "models/SuziFlatModel.h"
#include "models/GiftModel.h"

#include "CubeMap.h"

#include "Move.h"
#include "Scale.h"
#include "Rotate.h"
#include "Light.h"

class Scene {
private:
    CubeMap *cubemap = nullptr;
    std::vector<ShaderManager *> shaders;
    std::vector<Drawable *> drawables;
protected:
    void create_axes(ShaderManager *shader);
public:
    virtual void init() = 0;

    virtual Scene *clone() = 0;

    virtual ~Scene() = default;

    ShaderManager *add_shader(ShaderManager *shader);

    Drawable *add_drawable(Drawable *drawable);

    void draw();

    void link_shaders(Camera *camera, Window *window);

    void link_lights();

    void add_cubemap(string folder);
};


#endif //ZPG_PROJECT_SCENE_H
