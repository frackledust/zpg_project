//
// Created by pavli on 13/11/2022.
//

#ifndef ZPG_PROJECT_CUBEMAP_H
#define ZPG_PROJECT_CUBEMAP_H


#include "Drawable.h"
#include "models/CubeMapModel.h"

class CubeMap : public Drawable {
public:
    CubeMap(const std::string& folder) : Drawable(new CubeMapModel()) {
        std::vector<std::string> paths{"right.jpg", "left.jpg", "top.jpg", "bottom.jpg", "front.jpg", "back.jpg"};
//        std::vector<std::string> paths{"posx.jpg", "negx.jpg", "posy.jpg", "negy.jpg", "posz.jpg", "negz.jpg"};

        link_shader(new ShaderManager("../shaders/cubemap.vsh", "../shaders/cubemap.fsh"));

        link_texture(folder, paths);
    };

    ShaderManager *get_shader() {
        return shader_manager;
    }
};


#endif //ZPG_PROJECT_CUBEMAP_H
