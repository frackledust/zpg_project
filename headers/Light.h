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
    LightType type;
    glm::vec3 position = glm::vec3(0, 0, 0);
    glm::vec3 direction = glm::vec3(0, 1, 0);
    float cut_off = glm::cos(glm::radians(12.5f));
    float cut_out_off = glm::cos(glm::radians(15.0f));

public:
    Light(LightType type, float x, float y, float z) {
        if (type == DIR) {
            this->type = DIR;
            direction = glm::vec3(x, y, z);
        } else {
            this->type = POINT;
            position = glm::vec3(x, y, z);
        }
    }

    Light(LightType type, glm::vec3 position, glm::vec3 direction) {
        this->type = type;
        this->position = position;
        this->direction = direction;
    }

    [[nodiscard]] glm::vec3 get_position() const { return position; }

    [[nodiscard]] glm::vec3 get_direction() const { return direction; }

    [[nodiscard]] float get_cut_off() const { return cut_off; }

    [[nodiscard]] float get_cut_out_off() const { return cut_out_off; }

    [[nodiscard]] int get_type() const { return type; }
};


#endif //ZPG_PROJECT_LIGHT_H
