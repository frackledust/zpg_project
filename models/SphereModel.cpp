//
// Created by pavli on 02/11/2022.
//

#include "SphereModel.h"
#include "data/sphere.h"

SphereModel::SphereModel() : DataModel(sizeof(sphere), sphere, 2880, 3, true){}
