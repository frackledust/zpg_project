//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DRAWABLE_H
#define ZPG_PROJECT_DRAWABLE_H

#include "DataModel.h"
#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"

class Drawable {
public:
    DataModel * dataModel;
    glm::mat4 matrix;

    Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color);
    Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color, glm::mat4 matrix);
};


#endif //ZPG_PROJECT_DRAWABLE_H
