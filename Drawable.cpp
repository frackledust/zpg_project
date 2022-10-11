//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"

Drawable::Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color) {
    this->dataModel = new DataModel(size, data, vertex_count, vertex_size, has_color);
}

Drawable::Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color, glm::mat4 matrix)
:   Drawable(size, data, vertex_count, vertex_size, has_color){
    this->matrix = matrix;
}

void Drawable::render() {
    shaderManager->use_shaders();
    shaderManager->use_matrix(matrix);
    dataModel->draw();
}

void Drawable::link_shader(ShaderManager * shader) {
    this->shaderManager = shader;
}
