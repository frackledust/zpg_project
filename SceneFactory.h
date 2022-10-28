//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SCENEFACTORY_H
#define ZPG_PROJECT_SCENEFACTORY_H

#include <string>
#include <map>
#include <memory>
#include "Scene.h"
#include "scenes/SpheresDiffScene.h"
#include "scenes/SpheresPhongScene.h"

class SceneFactory {
    std::map<std::string, std::shared_ptr<Scene>> prototypes;

    SceneFactory() {
        prototypes.insert({ "SpheresDiffScene", make_shared<SpheresDiffScene>()});
        prototypes.insert({ "SpheresPhongScene", make_shared<SpheresPhongScene>()});
    }
    static SceneFactory *instance;
public:
    Scene* create_scene(const string& shape) {
        auto it = prototypes[shape];
        return it->clone();
    }

    static SceneFactory *get_instance();
};


#endif //ZPG_PROJECT_SCENEFACTORY_H
