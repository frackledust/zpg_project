//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_OBSERVER_H
#define ZPG_PROJECT_OBSERVER_H

#include "Subject.h"
#include "Event.h"

class Subject;

class Observer {
public:
    virtual void update(Subject* subject, Event event) {}

    virtual ~Observer() = default;
};


#endif //ZPG_PROJECT_OBSERVER_H
