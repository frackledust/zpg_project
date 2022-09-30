cmake_minimum_required(VERSION 3.16)
project(zpg_project)

set(SOURCE_FILES main.cpp VAO.cpp VBO.cpp VBO.h ShaderManager.cpp ShaderManager.h Window.cpp Window.h App.cpp App.h CallbackController.cpp CallbackController.h)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/lib/glew-x64)

set(CMAKE_CXX_STANDARD 14)

add_executable(zpg_project ${SOURCE_FILES})

target_link_libraries(zpg_project glfw3 gdi32 opengl32 glew32)
