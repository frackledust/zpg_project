//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_SHADERMANAGER_H
#define ZPG_PROJECT_SHADERMANAGER_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include "GL/glew.h"

class ShaderManager {
private:
    GLuint shaderProgram = glCreateProgram();
    std::vector<GLuint> shader_ids; //probably not needed
public:
    ShaderManager() = default;
    void add_shader(GLenum shader_type, const char** source);
    int link_shaders() const;
    void use_shaders() const;
};


#endif //ZPG_PROJECT_SHADERMANAGER_H
