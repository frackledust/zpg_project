//
// Created by pavli on 12/11/2022.
//

#include "PlainUVModel.h"
#include "data/plain_uv.h"

PlainUVModel::PlainUVModel() : DataModel(sizeof(plain), plain, 6, 3, true, true) {}