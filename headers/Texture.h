//
// Created by pavli on 23/11/2022.
//

#ifndef ZPG_PROJECT_TEXTURE_H
#define ZPG_PROJECT_TEXTURE_H

#include "GL/glew.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class Texture {
    inline static std::map<std::string, GLuint> textures;

    GLuint texture_id;
public:
    Texture(const char *path, int colors);
    Texture(const std::string &folder, std::vector<std::string> paths);

    void bind() const;

    bool check_if_loaded(const char *path);
};


#endif //ZPG_PROJECT_TEXTURE_H
