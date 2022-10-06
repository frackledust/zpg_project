//
// Created by pavli on 30/09/2022.
//


#include "ShaderManager.h"
ShaderManager::ShaderManager(const char *vertex_shader, const char *fragment_shader, const char *matrix_name) {
    this->add_shader(GL_VERTEX_SHADER, &vertex_shader);
    this->add_shader(GL_FRAGMENT_SHADER, &fragment_shader);
    this->link_shaders();
    std::cout << "MATRIX ID: " << this->link_matrix("modelMatrix") << "\n";
}

void ShaderManager::add_shader(GLenum shader_type, const char** source) {
    GLuint shader = glCreateShader(shader_type);
    shader_ids.push_back(shader);
    glShaderSource(shader, 1, source, nullptr);
    glCompileShader(shader);
    glAttachShader(this->shaderProgram, shader);
}

int ShaderManager::link_shaders() const {
    glLinkProgram(this->shaderProgram);

    GLint status;
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(this->shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        auto* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(this->shaderProgram, infoLogLength, nullptr, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;

        exit(EXIT_FAILURE);
    }
    return 0;
}

void ShaderManager::use_shaders() const {
    glUseProgram(this->shaderProgram);
}

int ShaderManager::link_matrix(const char* matrix_name) const {
    return glGetUniformLocation(this->shaderProgram, matrix_name);
}
