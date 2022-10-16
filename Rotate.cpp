//
// Created by pavli on 16/10/2022.
//

#include "Rotate.h"

glm::mat4 Rotate::transform() const {
    auto trans = Transformable::transform();
    return glm::rotate(trans, (float)glfwGetTime() * glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));;
}
