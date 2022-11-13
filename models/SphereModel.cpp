//
// Created by pavli on 02/11/2022.
//

#include "SphereModel.h"
#include "data/sphere.h"

SphereModel::SphereModel() : DataModel(2880, sizeof(sphere), sphere, 3, 3) {}
