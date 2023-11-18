//
// Created by pavli on 03/11/2022.
//

#ifndef ZPG_PROJECT_SPOTLIGHT_H
#define ZPG_PROJECT_SPOTLIGHT_H

#include "Light.h"

class SpotLight : public Light {
    glm::vec3 position{};
    glm::vec3 direction{};
    float cut_off = glm::cos(glm::radians(15.f));
public:
    SpotLight(const glm::vec3 position, const glm::vec3 direction) : Light() {
        this->type = SPOT;
        this->position = position;
        this->direction = direction;
    }

    SpotLight* set_color(const float r, const float g, const float b) override{
        Light::set_color(r, g, b);
        return this;
    }

    [[nodiscard]] glm::vec3 get_position() const { return position; }

    [[nodiscard]] glm::vec3 get_direction() const { return direction; }

    [[nodiscard]] float get_cut_off() const { return cut_off; }
};


#endif //ZPG_PROJECT_SPOTLIGHT_H
