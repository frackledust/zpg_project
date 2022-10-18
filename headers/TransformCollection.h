//
// Created by pavli on 18/10/2022.
//

#ifndef ZPG_PROJECT_TRANSFORMCOLLECTION_H
#define ZPG_PROJECT_TRANSFORMCOLLECTION_H


#include "Transformable.h"
class TransformCollection : Transformable {
    std::vector<Transformable*> components;
    glm::mat4 transform() const;
    glm::mat4 transform(glm::mat4 mat) const;
};


#endif //ZPG_PROJECT_TRANSFORMCOLLECTION_H
