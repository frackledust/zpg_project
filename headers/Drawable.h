//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DRAWABLE_H
#define ZPG_PROJECT_DRAWABLE_H

#include "DataModel.h"
#include "ShaderManager.h"
#include "TransformCollection.h"
#include "Texture.h"

class Drawable {
private:
    bool plotted = false;
    std::shared_ptr<DataModel> data_model;
    std::shared_ptr<TransformCollection> transformable;
protected:
    std::shared_ptr<Texture> texture = nullptr;
    std::shared_ptr<Texture> texture_second = nullptr;

    std::shared_ptr<ShaderManager> shader_manager = nullptr;

    Drawable *link_texture(const string &folder, vector<string> paths);

public:
    explicit Drawable(std::shared_ptr<DataModel> data_model);

    Drawable(std::shared_ptr<DataModel> data_model, bool plotted);

    Drawable *link_shader(std::shared_ptr<ShaderManager> shader);

    void render();

    Drawable *add_transformation(std::shared_ptr<Transformable> transformation);

    std::shared_ptr<Transformable> get_transformation();

    Drawable *link_texture(const char *path, int colors = GL_RGB);

    [[nodiscard]] bool was_plotted() const;
};


#endif //ZPG_PROJECT_DRAWABLE_H
