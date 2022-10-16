//
// Created by pavli on 16/10/2022.
//

#include "Rotate.h"

glm::mat4 Rotate::transform() const {
    auto trans = Transformable::transform();
    auto a = glm::radians(angle);
    a = move ? (float)glfwGetTime() * a : a;
    return glm::rotate(trans, a, direction);;
}
