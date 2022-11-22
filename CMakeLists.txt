cmake_minimum_required(VERSION 3.16)
project(zpg_project)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SOURCES "*.cpp")
set(SHADER-LOAD ShaderLoader/ShaderLoader.h ShaderLoader/ShaderLoader.cpp)
file(GLOB MODELS "models/*.cpp")

# static libraries
link_directories(${PROJECT_SOURCE_DIR}/lib/assimp)
link_directories(${PROJECT_SOURCE_DIR}/lib/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/lib/glew-x64)

set(CMAKE_CXX_STANDARD 17)

add_executable(zpg_project ${SOURCES} ${SHADER-LOAD} ${MODELS})

target_link_libraries(zpg_project glfw3 gdi32 opengl32 glew32 assimpd)
