//
// Created by pavli on 02/11/2022.
//

#include "SuziSmoothModel.h"
#include "data/suzi_smooth.h"

SuziSmoothModel::SuziSmoothModel() : DataModel(sizeof(suziSmooth), suziSmooth, 2904, 3, true) {}
