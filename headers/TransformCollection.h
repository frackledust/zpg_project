//
// Created by pavli on 18/10/2022.
//

#ifndef ZPG_PROJECT_TRANSFORMCOLLECTION_H
#define ZPG_PROJECT_TRANSFORMCOLLECTION_H


#include <memory>
#include "Transformable.h"

class TransformCollection : public Transformable {
public:
    std::vector<std::shared_ptr<Transformable>> components;

    [[nodiscard]] glm::mat4 transform(glm::mat4 mat) override;

    [[nodiscard]] glm::mat4 transform() override;
};


#endif //ZPG_PROJECT_TRANSFORMCOLLECTION_H
