//
// Created by pavli on 05/10/2022.
//

#include "DataModel.h"

DataModel::DataModel(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color){
    this->vertex_count = vertex_count;
    VBO(size, data);

    this->vao = new VAO();
    int stride = has_color ? 2 * vertex_size : vertex_size;

    this->mode = GL_TRIANGLES;
    if (vertex_count % 3 != 0) {
        this->mode = GL_POLYGON;
    }
    if (vertex_count == 2) {
        this->mode = GL_LINE;
    }

    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    if (has_color) {
        vao->add_vertex(1, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                        (void *) (vertex_size * sizeof(float)));
    }
}

DataModel::DataModel(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color, bool has_uv){
    this->vertex_count = vertex_count;

    VBO(size, data);

    this->vao = new VAO();
    int stride = 8;

    this->mode = GL_TRIANGLES;

    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (vertex_size * sizeof(float)));
    vao->add_vertex(2, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (6 * sizeof(float)));
}


void DataModel::draw() const {
    vao->bind_vertex_array();
    glDrawArrays(this->mode, 0, this->vertex_count); //mode,first,count
}
