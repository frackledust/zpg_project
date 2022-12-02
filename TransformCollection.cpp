//
// Created by pavli on 18/10/2022.
//

#include "TransformCollection.h"

glm::mat4 TransformCollection::transform(glm::mat4 mat) {
    for (auto &c: components) {
        mat = c->transform(mat);
    }
    return mat;
}

glm::mat4 TransformCollection::transform() {
    return this->transform(glm::mat4(1.0f));
}
