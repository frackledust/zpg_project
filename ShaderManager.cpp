//
// Created by pavli on 30/09/2022.
//


#include "ShaderManager.h"

ShaderManager::ShaderManager(const char *vertex_shader_file, const char *fragment_shader_file) {
    string vertexShaderString = loadFile(vertex_shader_file);
    string fragmentShaderString = loadFile(fragment_shader_file);

    if (vertexShaderString.empty()) printf("Empty Vertex Shader\n");
    if (fragmentShaderString.empty()) printf("Empty Fragment Shader\n");

    const char *vertex = vertexShaderString.c_str();
    const char *fragment = fragmentShaderString.c_str();

    this->add_shader(GL_VERTEX_SHADER, &vertex);
    this->add_shader(GL_FRAGMENT_SHADER, &fragment);
    this->link_shaders();
}

void ShaderManager::add_shader(GLenum shader_type, const char **source) {
    GLuint shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, source, nullptr);
    glCompileShader(shader);
    glAttachShader(this->shaderProgram, shader);
}

int ShaderManager::link_shaders() const {
    glLinkProgram(this->shaderProgram);

    GLint status;
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLint infoLogLength;
        glGetProgramiv(this->shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        auto *strInfoLog = new GLchar[infoLogLength + 1];
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

ShaderManager *ShaderManager::link_matrix_name(const char *matrix_name) {
    glGetUniformLocation(this->shaderProgram, matrix_name);
    return this;
}

void ShaderManager::set_uniform(const char *matrix_name, glm::mat4 matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, matrix_name), 1, GL_FALSE, &(matrix)[0][0]);
}

void ShaderManager::update(const char *matrix_name, glm::mat4 matrix) {
    use_shaders();
    set_uniform(matrix_name, matrix);
}
