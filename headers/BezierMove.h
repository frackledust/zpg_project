//
// Created by pavli on 01/12/2022.
//

#ifndef ZPG_PROJECT_BEZIERMOVE_H
#define ZPG_PROJECT_BEZIERMOVE_H

#include "Transformable.h"

class BezierMove : public Transformable {
    glm::mat4 M = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0),
                            glm::vec4(3.0, -6.0, 3.0, 0),
                            glm::vec4(-3.0, 3.0, 0, 0),
                            glm::vec4(1, 0, 0, 0));
    float t = 0.5;
    float delta = 0.005;
    bool move = true;
public:
    BezierMove() : BezierMove(0.5, glm::mat4x3(glm::vec3(-1, 0, 0),
                                               glm::vec3(0, 1, 0),
                                               glm::vec3(0, -1, 0),
                                               glm::vec3(1, 0, 0))) {}

    explicit BezierMove(float t, glm::mat4x3 control_points, bool move = true) {
        this->t = t;
        this->M = M * glm::transpose(control_points); // control_points^T
        this->move = move;
    }

    [[nodiscard]] glm::mat4 transform() override;

    [[nodiscard]] glm::mat4 transform(glm::mat4 mat) override;
};


#endif //ZPG_PROJECT_BEZIERMOVE_H
