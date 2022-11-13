//
// Created by pavli on 02/11/2022.
//

#include "PlainModel.h"
#include "data/plain.h"

PlainModel::PlainModel() : DataModel(6, sizeof(plain), plain, 3, 3) {}