//
// Created by pavli on 02/11/2022.
//

#include "PlainModel.h"
#include "data/plain.h"

PlainModel::PlainModel() : DataModel(sizeof(plain), plain, 6, 3, true) {}