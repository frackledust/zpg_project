//
// Created by pavli on 16/10/2022.
//

#include "Move.h"

glm::mat4 Move::transform() {
    auto mat = Transformable::transform();
    return glm::translate(mat, direction);
}

glm::mat4 Move::transform(glm::mat4 mat) {
    return glm::translate(mat, direction);
}
