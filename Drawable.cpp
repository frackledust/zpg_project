//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"

Drawable::Drawable(std::shared_ptr<DataModel> data_model) {
    this->data_model = data_model;
    this->transformable = std::make_shared<TransformCollection>();
}

Drawable::Drawable(std::shared_ptr<DataModel> data_model, bool plotted) : Drawable(data_model) {
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

Drawable *Drawable::link_shader(std::shared_ptr<ShaderManager> shader) {
    this->shader_manager = shader;
    return this;
}

Drawable *Drawable::link_texture(const char *path, int colors) {
    if (texture == nullptr) {
        texture = std::make_shared<Texture>(path, colors);
    } else {
        texture_second = std::make_shared<Texture>(path, colors);
    }
    return this;
}

Drawable *Drawable::link_texture(const std::string &folder, std::vector<std::string> paths) {
    texture = std::make_shared<Texture>(folder, paths);
    return this;
}

Drawable *Drawable::add_transformation(std::shared_ptr<Transformable> transformation) {
    this->transformable->components.push_back(transformation);
    return this;
}

std::shared_ptr<Transformable> Drawable::get_transformation() {
    return this->transformable;
}


