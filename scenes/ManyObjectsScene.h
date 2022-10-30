//
// Created by pavli on 30/10/2022.
//

#ifndef ZPG_PROJECT_MANYOBJECTSSCENE_H
#define ZPG_PROJECT_MANYOBJECTSSCENE_H

#include "Scene.h"

class ManyObjectsScene : public Scene {

    void init() override;
    Scene* clone() override{ return new ManyObjectsScene();};
};


#endif //ZPG_PROJECT_MANYOBJECTSSCENE_H
