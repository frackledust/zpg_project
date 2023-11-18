//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_MOVE_H
#define ZPG_PROJECT_MOVE_H

#include "Transformable.h"
class Move : public Transformable {
    glm::vec3 direction = glm::vec3(1.0, 0.0, 0.0);
public:
    Move() = default;

    explicit Move(const glm::vec3 direction) : direction(direction) {}
    [[nodiscard]] glm::mat4 transform() override;
    [[nodiscard]] glm::mat4 transform(glm::mat4 mat) override;
};


#endif //ZPG_PROJECT_MOVE_H
