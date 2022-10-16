//
// Created by pavli on 16/10/2022.
//

#ifndef ZPG_PROJECT_ROTATE_H
#define ZPG_PROJECT_ROTATE_H


#include "Transformable.h"

class Rotate : public Transformable {
    int angle = 10;
public:
    Rotate() = default;
    explicit Rotate(int angle) : angle(angle){}
    glm::mat4 transform() const override;
};


#endif //ZPG_PROJECT_ROTATE_H
