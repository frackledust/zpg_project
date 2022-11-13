//
// Created by pavli on 02/11/2022.
//

#include "SuziFlatModel.h"
#include "data/suzi_flat.h"

SuziFlatModel::SuziFlatModel() : DataModel(2904, sizeof(suziFlat), suziFlat, 3, 3) {}
