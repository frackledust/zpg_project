//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_SHADERMANAGER_H
#define ZPG_PROJECT_SHADERMANAGER_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

#include "GL/glew.h"

class ShaderManager {
private:
    GLuint shaderProgram = glCreateProgram();
    std::vector<GLuint> shader_ids; //probably not needed
public:
    ShaderManager() = default;
    ShaderManager(const char *vertex_shader, const char *fragment_shader, const char *matrix_name);

    void add_shader(GLenum shader_type, const char** source);
    int link_shaders() const;
    void use_shaders() const;
    int link_matrix(const char *matrix_name) const;
};


#endif //ZPG_PROJECT_SHADERMANAGER_H
