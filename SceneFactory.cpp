//
// Created by pavli on 28/10/2022.
//

#include "SceneFactory.h"

SceneFactory *SceneFactory::get_instance() {
    if (instance == nullptr) {
        instance = new SceneFactory();
    }
    return instance;
}