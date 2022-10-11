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
#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"

class ShaderManager {
private:
    GLuint shaderProgram = glCreateProgram();
    std::vector<GLuint> shaderIds; //probably not needed
    GLint matrixID;
public:
    ShaderManager() = default;
    ShaderManager(const char *vertex_shader, const char *fragment_shader);
    ShaderManager(const char *vertex_shader, const char *fragment_shader, const char *matrix_name);

    void add_shader(GLenum shader_type, const char** source);
    int link_shaders() const;
    void use_shaders() const;
    int link_matrix_name(const char *matrix_name);
    void use_matrix(glm::mat4 matrix) const;


};


#endif //ZPG_PROJECT_SHADERMANAGER_H
