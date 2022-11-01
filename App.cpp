//
// Created by pavli on 30/09/2022.
//

#include "App.h"

App::~App() {
    delete window;
    delete camera;
    delete scene;
    glfwTerminate();
}


App::App(int width, int height) {
    auto cb = CallbackController::get_instance();
    cb->bind_callbacks();

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    window = new Window(width, height, "Hi");
    window->bind_callbacks();

    glewExperimental = GL_TRUE;
    glewInit();

    glfwSwapInterval(1);

    camera = new Camera();
//    scene = SceneFactory::get_instance()->create_scene("SpheresPhongScene");
    scene = SceneFactory::get_instance()->create_scene("SpheresDiffScene");
//    scene = SceneFactory::get_instance()->create_scene("ManyObjectsScene");
    if(scene == nullptr){
        fprintf(stderr, "ERROR: could not find the scene\n");
        exit(EXIT_FAILURE);
    }
    scene->init();
    scene->link_light(new Light(10, 0, 0));
    scene->link_shaders(camera, window);

    cb->registerObserver(camera);
    cb->set_window(window);

    print_info();
}

void App::print_info() {
    printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
    printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("Vendor %s\n", glGetString(GL_VENDOR));
    printf("Renderer %s\n", glGetString(GL_RENDERER));
    printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

void App::draw_frame() const {
    window->clear_view();

    camera->update_position(window);

    scene->draw();

    glfwPollEvents();
    window->update_view();
}

bool App::is_open() const {
    return window->is_open();
}







