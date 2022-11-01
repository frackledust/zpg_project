//
// Created by pavli on 01/11/2022.
//

#ifndef ZPG_PROJECT_LIGHT_H
#define ZPG_PROJECT_LIGHT_H


#include "glm/vec3.hpp"

class Light {
    glm::vec3 position = glm::vec3(-10, 0, 0);
    glm::vec3 direction;
public:
    Light(float x, float y, float z) {
        position = glm::vec3(x, y, z);
    }

    glm::vec3 get_position(){ return position;}
};


#endif //ZPG_PROJECT_LIGHT_H
