//
// Created by pavli on 03/11/2022.
//

#ifndef ZPG_PROJECT_POINTLIGHT_H
#define ZPG_PROJECT_POINTLIGHT_H

#include "Light.h"

class PointLight : public Light {
    glm::vec3 position = glm::vec3(0, 0, 0);
public:
    explicit PointLight(float x, float y, float z) : Light() {
        this->type = POINT;
        this->position = glm::vec3(x, y, z);
    }

    PointLight* set_color(float r, float g, float b) override{
        Light::set_color(r, g, b);
        return this;
    }

    [[nodiscard]] glm::vec3 get_position() const { return position; }
};


#endif //ZPG_PROJECT_POINTLIGHT_H
