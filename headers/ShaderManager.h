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

#include "ShaderLoader/ShaderLoader.h"
#include "Observer.h"
#include "Camera.h"
#include "Light.h"

class ShaderManager : public ShaderLoader, public Observer {
private:
    GLuint shaderProgram = glCreateProgram();

    void add_shader(GLenum shader_type, const char **source);

    void link_shaders() const;

public:
    ShaderManager() = default;

    ShaderManager(const char *vertex_shader_file, const char *fragment_shader_file);

    void use_shaders() const;

    ShaderManager *link_matrix_name(const char *matrix_name);

    void set_uniform(const char *matrix_name, glm::mat4 matrix) const;

    void set_uniform(const char *vec_name, glm::vec3 vec) const;

    void update(Subject *subject, Event event) override;

    void set_uniform(const char *vec_name, float value) const;

    void set_uniform(const std::string &light_name, const Light &light) const;
};


#endif //ZPG_PROJECT_SHADERMANAGER_H
