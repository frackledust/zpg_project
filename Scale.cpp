//
// Created by pavli on 16/10/2022.
//

#include "Scale.h"
glm::mat4 Scale::transform(glm::mat4 mat) const {
    return glm::scale(mat, direction);
}
