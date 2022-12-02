//
// Created by pavli on 16/10/2022.
//

#include "Rotate.h"

glm::mat4 Rotate::transform() {
    auto trans = Transformable::transform();
    return this->transform(trans);
}

glm::mat4 Rotate::transform(glm::mat4 mat) {
    auto a = glm::radians(angle);
    a = move ? (float) glfwGetTime() * a : a;
    return glm::rotate(mat, a, direction);;
}
