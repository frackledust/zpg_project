cmake_minimum_required(VERSION 3.16)
project(zpg_project)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/headers)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

file(GLOB SOURCES "*.cpp")
set(SHADER-LOAD ShaderLoader/ShaderLoader.h ShaderLoader/ShaderLoader.cpp)
file(GLOB MODELS "models/*.cpp")

# static libraries - used on winodws
link_directories(${PROJECT_SOURCE_DIR}/lib/assimp)
link_directories(${PROJECT_SOURCE_DIR}/lib/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/lib/glew-x64)


set(CMAKE_CXX_STANDARD 17)

add_executable(zpg_project ${SOURCES} ${SHADER-LOAD} ${MODELS})

# link libraries - windows
#target_link_libraries(zpg_project glfw3 gdi32 opengl32 glew32 assimpd)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(zpg_project glfw GLEW OpenGL assimp)