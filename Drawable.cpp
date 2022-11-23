//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"

Drawable::Drawable(DataModel *data_model) {
    this->data_model = data_model;
    this->transformable = new TransformCollection();
}

Drawable::Drawable(DataModel *data_model, bool plotted) : Drawable(data_model) {
    this->plotted = plotted;
}

bool Drawable::was_plotted() const {
    return plotted;
}

void Drawable::render() {
    auto model = transformable->transform();

    if (shader_manager) {
        shader_manager->use_shaders();
        shader_manager->set_uniform("model", model);
    }

    if (texture) {
        glActiveTexture(GL_TEXTURE0);
        texture->bind();
    }

    if(texture_second){
        glActiveTexture(GL_TEXTURE1);
        texture_second->bind();
    }

    data_model->draw();
}

Drawable *Drawable::link_shader(ShaderManager *shader) {
    this->shader_manager = shader;
    return this;
}

Drawable *Drawable::link_texture(const char *path, int colors) {
    if (texture == nullptr) {
        texture = new Texture(path, colors);
    } else {
        texture_second = new Texture(path, colors);
    }
    return this;
}

Drawable *Drawable::link_texture(const std::string &folder, std::vector<std::string> paths) {
    texture = new Texture(folder, paths);
    return this;
}

Drawable *Drawable::add_transformation(Transformable *transformation) {
    this->transformable->components.push_back(transformation);
    return this;
}

Transformable *Drawable::get_transformation() {
    return this->transformable;
}


