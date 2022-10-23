//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_VBO_H
#define ZPG_PROJECT_VBO_H

#include "GL/glew.h"

class VBO {
private:
    GLuint VBO_id = 0;
public:
    VBO();
    VBO(GLsizeiptr size, const void *data);

    void bind_buffer() const;
    void set_buffer(GLsizeiptr size, const void *data);
};


#endif //ZPG_PROJECT_VBO_H
