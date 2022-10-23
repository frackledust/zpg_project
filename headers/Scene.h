//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_SCENE_H
#define ZPG_PROJECT_SCENE_H


#include "Drawable.h"

class Scene {
private:
    std::vector<Drawable *> drawables;
public:
    Drawable *add_drawable(Drawable *drawable);
    void draw(float *proj, float *view);

    void init();
};


#endif //ZPG_PROJECT_SCENE_H
