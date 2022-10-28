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

    virtual void notify_observers(){
        for(auto& o : observers){
            o->update();
        }
    };

    virtual void notify_observers(const char* matrix_name, glm::mat4 matrix){
        for(auto& o : observers){
            o->update(matrix_name, matrix);
        }
    };

    virtual void notify_observers(float x, float y){
        for(auto& o : observers){
            o->update(x, y);
        }
    };
};

#endif //ZPG_PROJECT_SUBJECT_H
