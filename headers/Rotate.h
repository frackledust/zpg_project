//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_ROTATE_H
#define ZPG_PROJECT_ROTATE_H


#include "Transformable.h"

class Rotate : public Transformable {
    float angle = 10;
    bool move = false;
    glm::vec3 direction = glm::vec3(1.0, 0.0, 0.0);
public:
    Rotate() = default;

    explicit Rotate(const float angle, const glm::vec3 direction) : angle(angle), direction(direction) {}

    explicit Rotate(const float angle, const glm::vec3 direction, const bool move) : angle(angle), direction(direction), move(move) {}

    [[nodiscard]] glm::mat4 transform() override;

    [[nodiscard]] glm::mat4 transform(glm::mat4 mat) override;
};


#endif //ZPG_PROJECT_ROTATE_H
