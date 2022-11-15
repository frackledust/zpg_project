//
// Created by pavli on 05/10/2022.
//

#ifndef ZPG_PROJECT_DRAWABLE_H
#define ZPG_PROJECT_DRAWABLE_H

#include "DataModel.h"
#include "ShaderManager.h"
#include "TransformCollection.h"

class Drawable {
private:
    DataModel *data_model;
    TransformCollection *transformable;
protected:
    GLuint texture;

    ShaderManager *shader_manager = nullptr;

    Drawable *link_texture(const string &folder, vector<string> paths);

public:
    explicit Drawable(DataModel *data_model);

    Drawable *link_shader(ShaderManager *shader);

    void render();

    Drawable *add_transformation(Transformable *transformation);

    Transformable *get_transformation();

    Drawable *link_texture(const char *path, int colors = GL_RGB);
};


#endif //ZPG_PROJECT_DRAWABLE_H
