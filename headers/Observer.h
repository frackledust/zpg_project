//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_OBSERVER_H
#define ZPG_PROJECT_OBSERVER_H

#include "glm/fwd.hpp"
#include "glm/detail/type_mat4x4.hpp"
#include "Subject.h"
#include "Event.h"

class Subject;

class Observer { ;
public:
    virtual void update(Subject* subject, Event event) {}
};


#endif //ZPG_PROJECT_OBSERVER_H
