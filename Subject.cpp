//
// Created by pavli on 02/11/2022.
//
#include "Subject.h"

void Subject::notify_observers(Event event) {
    for (auto &o: observers) {
        o->update(this, event);
    }
}
