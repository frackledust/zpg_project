//
// Created by pavli on 03/11/2022.
//


#ifndef ZPG_PROJECT_DIRLIGHT_H

#include "Light.h"

class DirLight : public Light {
    glm::vec3 direction = glm::vec3(0, 1, 0);
public:
    explicit DirLight(float xd, float yd, float zd) : Light() {
        this->type = DIR;
        this->direction = glm::vec3(xd, yd, zd);
    }

    DirLight* set_color(float r, float g, float b) override{
        Light::set_color(r, g, b);
        return this;
    }

    [[nodiscard]] glm::vec3 get_direction() const { return this->direction; }

};

#endif //ZPG_PROJECT_DIRLIGHT_H
