#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &this->VAO_id);
    glBindVertexArray(this->VAO_id);
    glEnableVertexAttribArray(0);
}

VAO::VAO(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) : VAO() {
    set_vertex(index, size, type, normalized, stride, pointer);
}

void VAO::set_vertex(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}


void VAO::bind_vertex_array() const {
    glBindVertexArray(this->VAO_id);
}



