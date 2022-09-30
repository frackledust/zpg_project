//
// Created by pavli on 30/09/2022.
//

#include "VBO.h"

VBO::VBO() {
    glGenBuffers(1, &this->VBO_id);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO_id);
}

VBO::VBO(GLsizeiptr size, const void *data) : VBO() {
    set_buffer(size, data);
}

void VBO::set_buffer(GLsizeiptr size, const void *data) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    this->bind_buffer();
}

void VBO::bind_buffer() const {
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO_id);
}
