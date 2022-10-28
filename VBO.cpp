//
// Created by pavli on 30/09/2022.
//

#include "VBO.h"

VBO::VBO() {
    glGenBuffers(1, &this->VBO_id);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO_id);
}

VBO::VBO(GLsizeiptr size, const void *data) : VBO() {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}


