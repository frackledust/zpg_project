//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DATAMODEL_H
#define ZPG_PROJECT_DATAMODEL_H


#include "VBO.h"
#include "VAO.h"

class DataModel {
private:
    VBO* vbo;
    int vertex_size;
    bool has_colour;
public:
    DataModel(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color);

    VAO* vao;
    int vertex_count;
    GLenum mode;
};


#endif //ZPG_PROJECT_DATAMODEL_H
