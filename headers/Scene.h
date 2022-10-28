//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_SCENE_H
#define ZPG_PROJECT_SCENE_H


#include "Drawable.h"
#include "Camera.h"

class Scene {
private:
    std::vector<ShaderManager *> shaders;
    std::vector<Drawable *> drawables;
public:
    ShaderManager *add_shader(ShaderManager *shader);

    Drawable *add_drawable(Drawable *drawable);

    void draw(const glm::mat4 &proj, const glm::mat4 &view);

    void init() {};

    void init_spheres_phong();

    void init_spheres_different();

    void link_shaders(Camera *camera, Window *window);
};


#endif //ZPG_PROJECT_SCENE_H
