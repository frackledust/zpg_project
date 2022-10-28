//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SPHERESDIFFSCENE_H
#define ZPG_PROJECT_SPHERESDIFFSCENE_H


#include "Scene.h"

class SpheresDiffScene : public Scene {
    void init() override;
    Scene* clone() override{ return new SpheresDiffScene();};
};


#endif //ZPG_PROJECT_SPHERESDIFFSCENE_H
