//
// Created by pavli on 01/11/2022.
//

#ifndef ZPG_PROJECT_LIGHT_H
#define ZPG_PROJECT_LIGHT_H


#include "glm/vec3.hpp"

enum LightType {
    OFF = 0, DIR = 1, POINT = 2, SPOT = 3
};

class Light {
protected:
    LightType type = OFF;
    glm::vec3 color = glm::vec3( 0.385, 0.647, 0.812);
    Light() = default;
public:
    [[nodiscard]] int get_type() const { return type; }

    virtual Light* set_color(float r, float g, float b){
        this->color = glm::vec3(r, g, b);
        return this;
    }

    [[nodiscard]] glm::vec3 get_color() const { return color; }
};

#endif //ZPG_PROJECT_LIGHT_H
