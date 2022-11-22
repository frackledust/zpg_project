//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DATAMODEL_H
#define ZPG_PROJECT_DATAMODEL_H


#include "VBO.h"
#include "VAO.h"

class DataModel {
private:

    GLenum mode = GL_TRIANGLES;
    int vertex_count{};
protected:
    DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size);

    DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size, int uv_size);

    DataModel(int vertex_count, GLsizeiptr size, const void *data);

    VAO *vao{};
public:
    void draw() const;

    DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size);

    explicit DataModel(const char *file_path);
};


#endif //ZPG_PROJECT_DATAMODEL_H
