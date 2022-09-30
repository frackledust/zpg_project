//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_VAO_H
#define ZPG_PROJECT_VAO_H

#include "GL/glew.h"

class VAO {
private:
    GLuint VAO_id = 0;
public:
    VAO();
    VAO(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    static void set_vertex(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
    void bind_vertex_array() const;
};


#endif //ZPG_PROJECT_VAO_H
