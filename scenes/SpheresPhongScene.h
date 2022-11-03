//
// Created by pavli on 28/10/2022.
//

#ifndef ZPG_PROJECT_SPHERESPHONGSCENE_H
#define ZPG_PROJECT_SPHERESPHONGSCENE_H


#include "Scene.h"

class SpheresPhongScene : public Scene {

    void init() override;

    Scene *clone() override { return new SpheresPhongScene(); };
};


#endif //ZPG_PROJECT_SPHERESPHONGSCENE_H
