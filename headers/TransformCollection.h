//
// Created by pavli on 18/10/2022.
//

#ifndef ZPG_PROJECT_TRANSFORMCOLLECTION_H
#define ZPG_PROJECT_TRANSFORMCOLLECTION_H


#include "Transformable.h"

class TransformCollection : public Transformable {

    glm::mat4 transform(glm::mat4 mat) const;

public:
    glm::mat4 transform() const;

    std::vector<Transformable *> components;
};


#endif //ZPG_PROJECT_TRANSFORMCOLLECTION_H
