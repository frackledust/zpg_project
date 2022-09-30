#include "VAO.h"

VAO::VAO() {
    glGenVertexArrays(1, &this->VAO_id);
    glBindVertexArray(this->VAO_id);
}

VAO::VAO(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) : VAO() {
    add_vertex(index, size, type, normalized, stride, pointer);
}

void VAO::add_vertex(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(vertex_count);
    vertex_count++;
}


void VAO::bind_vertex_array() const {
    glBindVertexArray(this->VAO_id);
}



