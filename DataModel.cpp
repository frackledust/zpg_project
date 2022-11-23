//
// Created by pavli on 05/10/2022.
//

#include "DataModel.h"

#include <assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>

void DataModel::load_data(const char *file_path, int stride) {
    unsigned int count = 0;
    Assimp::Importer importer;
    unsigned int importOptions = aiProcess_Triangulate
                                 | aiProcess_OptimizeMeshes              // join small fragments
                                 | aiProcess_JoinIdenticalVertices
                                 | aiProcess_CalcTangentSpace;           // tangent for normal map
    const aiScene *scene = importer.ReadFile(file_path, importOptions);
    std::vector<float> data;
    if (scene) {
        aiMesh *mesh = scene->mMeshes[0]; // take first object
        count = mesh->mNumFaces * 3; // each triange 3 verticles
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
            for (unsigned int j = 0; j < 3; j++) {
                if (stride < COORDS_ONLY) return;
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].z);
                if (stride < NORMAL_DATA) continue;
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].z);
                if (stride < UV_DATA) continue;
                data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].y);
                if (stride < TANGENT_DATA) continue;
                data.push_back(mesh->mTangents[mesh->mFaces[i].mIndices[j]].x);
                data.push_back(mesh->mTangents[mesh->mFaces[i].mIndices[j]].y);
                data.push_back(mesh->mTangents[mesh->mFaces[i].mIndices[j]].z);
            }
        }
    }

    this->vertex_count = (int) count;

    VBO((GLsizeiptr) (data.size() * sizeof(float)), &data[0]);
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data) {
    this->vertex_count = vertex_count;

    VBO(size, data);

    this->vao = new VAO();

    if (vertex_count % 3 != 0) { this->mode = GL_POLYGON; }
    if (vertex_count == 2) { this->mode = GL_LINE; }
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size)
        : DataModel(vertex_count, size, data) {

    int stride = vertex_size;
    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size)
        : DataModel(vertex_count, size, data) {

    int stride = vertex_size + normal_size;
    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, normal_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (vertex_size * sizeof(float)));
}

DataModel::DataModel(int vertex_count, GLsizeiptr size, const void *data, int vertex_size, int normal_size,
                     int uv_size) : DataModel(vertex_count, size, data) {

    int uv_offset = vertex_size + normal_size;
    int stride = uv_offset + uv_size;

    vao->add_vertex(0, vertex_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, normal_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (vertex_size * sizeof(float)));
    vao->add_vertex(2, uv_size, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)),
                    (void *) (uv_offset * sizeof(float)));
}

DataModel::DataModel(const char *file_path, int stride) {
    load_data(file_path, stride);

    this->vao = new VAO();
    if (stride < COORDS_ONLY) return;
    vao->add_vertex(0, 3, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (0 * sizeof(float)));
    if (stride < NORMAL_DATA) return;
    vao->add_vertex(1, 3, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (3 * sizeof(float)));
    if (stride < UV_DATA) return;
    vao->add_vertex(2, 2, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (6 * sizeof(float)));
    if (stride < TANGENT_DATA) return;
    vao->add_vertex(3, 3, GL_FLOAT, GL_FALSE, (int) (stride * sizeof(float)), (void *) (8 * sizeof(float)));
}

void DataModel::draw() const {
    vao->bind_vertex_array();
    glDrawArrays(this->mode, 0, this->vertex_count); //mode,first,count
}
