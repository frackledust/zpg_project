#include <cstdlib>
#include <iostream>

#include "App.h"
#include "CallbackController.h"

int main() {
    App *app = new App(800, 600);
    auto cb = CallbackController::getInstance();
    cb->registerObserver(app->camera);
    cb->app_window = app->window;

    while (app->is_open()) {
        app->draw_frame();
    }

    delete app;
    exit(EXIT_SUCCESS);
}
