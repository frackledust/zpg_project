//
// Created by pavli on 23/10/2022.
//

#ifndef ZPG_PROJECT_SUBJECT_H
#define ZPG_PROJECT_SUBJECT_H

#include "vector"
#include "Observer.h"

class Subject {
private:
    std::vector<Observer*> observers;
public:
    virtual void registerObserver(Observer *observer){
        observers.push_back(observer);
    };

    virtual void removeObserver(Observer *observer){};

    virtual void notifyObservers(){};
};

#endif //ZPG_PROJECT_SUBJECT_H
