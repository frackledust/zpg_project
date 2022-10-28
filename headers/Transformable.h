//
// Created by pavli on 06/10/2022.
//

#ifndef ZPG_PROJECT_TRANSFORMABLE_H
#define ZPG_PROJECT_TRANSFORMABLE_H

#include "GLFW/glfw3.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>


class Transformable {
public:
    [[nodiscard]] virtual glm::mat4 transform() const;

    [[nodiscard]] virtual glm::mat4 transform(glm::mat4 mat) const;
};


#endif //ZPG_PROJECT_TRANSFORMABLE_H
