//
// Created by pavli on 01/12/2022.
//

#include "BezierMove.h"

glm::mat4 BezierMove::transform() {
    auto mat = Transformable::transform();
    return this->transform(mat);
}

glm::mat4 BezierMove::transform(glm::mat4 mat) {
    glm::vec4 parameters = glm::vec4(t * t * t, t * t, t, 1.0f);
    glm::vec3 p = parameters * M;
    mat = glm::translate(mat, p);

    if(move){
        if (t >= 1.0f || t <= 0.0f) delta *= -1;
        t += delta;
    }

    return mat;
}
