//
// Created by pavli on 02/11/2022.
//

#include "SuziSmoothModel.h"
#include "data/suzi_smooth.h"

SuziSmoothModel::SuziSmoothModel() : DataModel(2904, sizeof(suziSmooth), suziSmooth, 3, 3) {}
