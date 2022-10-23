//
// Created by pavli on 06/10/2022.
//

#include "Transformable.h"

glm::mat4 Transformable::transform(glm::mat4 mat) const {
    return mat;
}

glm::mat4 Transformable::transform() const {
    return this->transform(glm::mat4(1.0f));
}

