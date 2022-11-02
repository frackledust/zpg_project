//
// Created by pavli on 02/11/2022.
//

#include "SuziFlatModel.h"
#include "data/suzi_flat.h"

SuziFlatModel::SuziFlatModel() : DataModel(sizeof(suziFlat), suziFlat, 2904, 3, true) {}
