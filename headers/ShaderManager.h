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
#include "../ShaderLoader/ShaderLoader.h"
#include "Observer.h"

class ShaderManager : public ShaderLoader, public Observer {
private:
    GLuint shaderProgram = glCreateProgram();
    std::vector<GLuint> shaderIds; //probably not needed
public:
    ShaderManager() = default;

    ShaderManager(const char *vertex_shader_file, const char *fragment_shader_file);

    void add_shader(GLenum shader_type, const char **source);

    int link_shaders() const;

    void use_shaders() const;

    ShaderManager *link_matrix_name(const char *matrix_name);

    void set_uniform(const char *matrix_name, glm::mat4 matrix) const;

    void update(const char* matrix_name, glm::mat4 matrix) override;
};


#endif //ZPG_PROJECT_SHADERMANAGER_H
