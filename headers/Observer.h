//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_OBSERVER_H
#define ZPG_PROJECT_OBSERVER_H


class Observer { ;
public:
    virtual void update() {}
    virtual void update(float x, float y) {};
};


#endif //ZPG_PROJECT_OBSERVER_H
