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
    explicit Rotate(float angle, glm::vec3 direction) : angle(angle), direction(direction){}
    explicit Rotate(float angle, glm::vec3 direction, bool move) : angle(angle), direction(direction), move(move){}
    glm::mat4 transform() const override;
    glm::mat4 transform(glm::mat4 mat) const override;
};


#endif //ZPG_PROJECT_ROTATE_H
