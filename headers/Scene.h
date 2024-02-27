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
#include "BezierMove.h"

#include "Light.h"

class Scene {
private:
    CubeMap *cubemap = nullptr;
    std::vector<Drawable *> drawables;
    std::vector<Light *> lights;
protected:
    void create_axes(std::shared_ptr<ShaderManager> shader);

    std::vector<std::shared_ptr<ShaderManager>> shaders;
public:
    virtual void init() = 0;

    virtual Scene *clone() = 0;

    virtual ~Scene(){
        for (int i = 0; i < drawables.size(); i++) {
            delete drawables[i];
        }

        // delete lights
        for (int i = 0; i < lights.size(); i++) {
            delete lights[i];
        }

        delete cubemap;
    }

    std::shared_ptr<ShaderManager> add_shader(std::shared_ptr<ShaderManager> shader);

    Drawable *add_drawable(Drawable *drawable);

    void draw();

    void link_shaders(Camera *camera, Window *window);

    virtual void link_lights();

    void add_cubemap(string folder);

    bool can_delete_on_index(int i);
};


#endif //ZPG_PROJECT_SCENE_H
