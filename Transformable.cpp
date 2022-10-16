//
// Created by pavli on 06/10/2022.
//

#include "Transformable.h"

glm::mat4 Transformable::transform() const {

//    trans = glm::rotate(trans, (float)glfwGetTime() * glm::radians(1.0f), glm::vec3(0.0, 0.0, 1.0));
//    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(10.0f), glm::vec3(0.5f, 1.0f, 0.0f));
//    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(1.0, 1.0, 1.0));
//    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    auto trans = glm::mat4(1.0f);
    return  trans;
}

