//
// Created by pavli on 05/10/2022.
//

#include "Drawable.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Drawable::Drawable(DataModel *data_model) {
    this->data_model = data_model;
    this->transformable = new TransformCollection();
}

void Drawable::render() {
    shader_manager->use_shaders();

    auto model = transformable->transform();
    shader_manager->set_uniform("model", model);
    glBindTexture(GL_TEXTURE_2D, texture);
    data_model->draw();
}

Drawable *Drawable::link_shader(ShaderManager *shader) {
    this->shader_manager = shader;
    return this;
}

Drawable *Drawable::link_texture(const char *path, int colors) {
    stbi_set_flip_vertically_on_load(true);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, colors, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return this;
}

Drawable *Drawable::add_transformation(Transformable *transformation) {
    this->transformable->components.push_back(transformation);
    return this;
}

Transformable *Drawable::get_transformation() {
    return this->transformable;
}


