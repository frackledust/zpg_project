//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"

Drawable::Drawable(DataModel *data_model) {
    this->data_model = data_model;
    this->transformable = new TransformCollection();
}

void Drawable::render() {
    shader_manager->use_shaders();

    auto model = transformable->transform();
    shader_manager->set_uniform("model", model);

    data_model->draw();
}

Drawable *Drawable::link_shader(ShaderManager *shader) {
    this->shader_manager = shader;
    return this;
}

Drawable *Drawable::add_transformation(Transformable *transformation) {
    this->transformable->components.push_back(transformation);
    return this;
}

Transformable *Drawable::get_transformation() {
    return this->transformable;
}