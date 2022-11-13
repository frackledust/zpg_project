//
// Created by pavli on 12/11/2022.
//

#include "PlainUVModel.h"
#include "data/plain_uv.h"

PlainUVModel::PlainUVModel() : DataModel(6, sizeof(plain), plain, 3, 3, 2) {}