#include <cstdlib>
#include <iostream>

#include "App.h"
#include "CallbackController.h"

int main() {
    App *app = new App(800, 600);

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
