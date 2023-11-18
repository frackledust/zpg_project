//
// Created by pavli on 13/11/2022.
//

#ifndef ZPG_PROJECT_CUBEMAP_H
#define ZPG_PROJECT_CUBEMAP_H


#include "Drawable.h"
#include "models/CubeMapModel.h"

class CubeMap : public Drawable {
public:
    explicit CubeMap(const std::string& folder) : Drawable(std::make_shared<CubeMapModel>()) {
        const std::vector<std::string> paths{"right.jpg", "left.jpg", "top.jpg", "bottom.jpg", "front.jpg", "back.jpg"};

        link_shader(std::make_shared<ShaderManager>("../shaders/cubemap.vsh", "../shaders/cubemap.fsh"));

        link_texture(folder, paths);
    }

    std::shared_ptr<ShaderManager> get_shader() {
        return shader_manager;
    }
};


#endif //ZPG_PROJECT_CUBEMAP_H
