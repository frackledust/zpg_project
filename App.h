//
// Created by pavli on 30/09/2022.
//

#ifndef ZPG_PROJECT_APP_H
#define ZPG_PROJECT_APP_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstdio>
#include <cstdlib>

class App {
public:
    static void init_glfw();
    static void init_glew();
    static void print_info();
};


#endif //ZPG_PROJECT_APP_H
