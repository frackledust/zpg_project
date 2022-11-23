//
// Created by pavli on 23/11/2022.
//

#ifndef ZPG_PROJECT_TEXTURE_H
#define ZPG_PROJECT_TEXTURE_H

#include "GL/glew.h"
#include <vector>
#include <string>
#include <iostream>

class Texture {
    GLenum texture_type = GL_TEXTURE_2D;
public:
    Texture(const char *path, int colors);
    Texture(const std::string &folder, std::vector<std::string> paths);

    void bind() const;

    GLuint texture_id;
};


#endif //ZPG_PROJECT_TEXTURE_H
