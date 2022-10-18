//
// Created by pavli on 30/09/2022.
//


#include "ShaderManager.h"

ShaderManager::ShaderManager(const char *vertex_shader, const char *fragment_shader) {
    this->add_shader(GL_VERTEX_SHADER, &vertex_shader);
    this->add_shader(GL_FRAGMENT_SHADER, &fragment_shader);
    this->link_shaders();
}

void ShaderManager::add_shader(GLenum shader_type, const char** source) {
    GLuint shader = glCreateShader(shader_type);
    shaderIds.push_back(shader);
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

ShaderManager* ShaderManager::link_matrix_name(const char* matrix_name) {
    this->matrixID = glGetUniformLocation(this->shaderProgram, matrix_name);
    std::cout << "MATRIX " << matrix_name << " ID: " << this->matrixID << "\n";
    return this;
}

void ShaderManager::set_uniform(int matrix_id, glm::mat4 matrix) const {

}
