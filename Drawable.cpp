//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"


Drawable::Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color) {
    this->dataModel = new DataModel(size, data, vertex_count, vertex_size, has_color);
    this->transformable = new TransformCollection();
}

void Drawable::render() {

    auto model = transformable->transform();
    glUniformMatrix4fv(2, 1, GL_FALSE, &model[0][0]);

    dataModel->draw();
}

Drawable * Drawable::link_shader(ShaderManager * shader) {
    this->shaderManager = shader;
    return this;
}

Drawable * Drawable::add_transformation(Transformable *transformation) {
    this->transformable->components.push_back(transformation);
    return this;
}

Transformable * Drawable::get_transformation() {
    return this->transformable;
}
