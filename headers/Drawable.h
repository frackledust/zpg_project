//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DRAWABLE_H
#define ZPG_PROJECT_DRAWABLE_H

#include "DataModel.h"
#include <GLFW/glfw3.h>
#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"
#include "ShaderManager.h"
#include "Rotate.h"
#include "TransformCollection.h"

class Drawable {
private:
    DataModel *dataModel;
    TransformCollection *transformable;
public:
    Drawable(GLsizeiptr size, const void *data, int vertex_count, int vertex_size, bool has_color);

    Drawable *link_shader(ShaderManager *shader);

    void render();


    Drawable *add_transformation(Transformable *transformation);

    Transformable *get_transformation();

    ShaderManager *shaderManager;
};


#endif //ZPG_PROJECT_DRAWABLE_H
