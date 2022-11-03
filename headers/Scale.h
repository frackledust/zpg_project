//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_SCALE_H
#define ZPG_PROJECT_SCALE_H

#include "Transformable.h"

class Scale : public Transformable {
    glm::vec3 direction = glm::vec3(1.0, 1.0, 1.0);
public:
    Scale() = default;

    explicit Scale(glm::vec3 direction) : direction(direction) {}

    [[nodiscard]] glm::mat4 transform(glm::mat4 mat) const override;
};


#endif //ZPG_PROJECT_SCALE_H
