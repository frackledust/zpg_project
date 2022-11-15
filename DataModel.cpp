//
// Created by pavli on 05/10/2022.
//

#include "DataModel.h"

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data) {
    this->vertex_count = vertex_count;

    VBO(size, data);

    this->vao = new VAO();

    if (vertex_count % 3 != 0) { this->mode = GL_POLYGON; }
    if (vertex_count == 2) { this->mode = GL_LINE; }
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size)
        : DataModel(vertex_count, size, data) {

    int stride = vertex_size;
    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size)
        : DataModel(vertex_count, size, data) {

    int stride = vertex_size + normal_size;
    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, normal_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (vertex_size * sizeof(float)));
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size,
                     int uv_size) : DataModel(vertex_count, size, data) {

    int uv_offset = vertex_size + normal_size;
    int stride = uv_offset + uv_size;

    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, normal_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (vertex_size * sizeof(float)));
    vao->add_vertex(2, uv_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (uv_offset * sizeof(float)));
}


void DataModel::draw() const {
    vao->bind_vertex_array();
    glDrawArrays(this->mode, 0, this->vertex_count); //mode,first,count
}
