//
// Created by pavli on 13/11/2022.
//

#include "CubeMapModel.h"
#include "data/cube.h"

CubeMapModel::CubeMapModel() : DataModel(36, sizeof(cube_data), cube_data){
    vao->add_vertex(0, 3, GL_FLOAT, GL_FALSE, (int) (6 * sizeof(float)), (void *) (0 * sizeof(float)));
    vao->add_vertex(1, 3, GL_FLOAT, GL_FALSE, (int) (6 * sizeof(float)), (void *) (3 * sizeof(float)));
    vao->add_vertex(2, 2, GL_FLOAT, GL_FALSE, (int) (6 * sizeof(float)), (void *) (0 * sizeof(float)));
}