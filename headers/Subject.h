//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_SUBJECT_H
#define ZPG_PROJECT_SUBJECT_H

#include "vector"
#include <bits/stdc++.h>
#include "Observer.h"
#include "Event.h"
class Observer;

class Subject {
protected:
    std::vector<Observer*> observers;
public:
    virtual void registerObserver(Observer *observer){
        observers.push_back(observer);
    }

    virtual void removeObserver(Observer *observer){
        std::remove(observers.begin(),observers.end(),observer);
    }

    virtual void notify_observers(Event event);

    virtual ~Subject() = default;
};

#endif //ZPG_PROJECT_SUBJECT_H
