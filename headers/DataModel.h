//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DATAMODEL_H
#define ZPG_PROJECT_DATAMODEL_H


#include "VBO.h"
#include "VAO.h"

class DataModel {
private:
    VAO *vao;

    GLenum mode;
    int vertex_count;
    bool has_colour;
public:
    DataModel(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color);

    DataModel();

    void draw() const;
};


#endif //ZPG_PROJECT_DATAMODEL_H
