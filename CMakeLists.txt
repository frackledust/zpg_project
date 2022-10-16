cmake_minimum_required(VERSION 3.16)
project(zpg_project)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/data)

file(GLOB SOURCES "*.cpp")

link_directories(${PROJECT_SOURCE_DIR}/lib/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/lib/glew-x64)

set(CMAKE_CXX_STANDARD 14)

add_executable(zpg_project ${SOURCES})

target_link_libraries(zpg_project glfw3 gdi32 opengl32 glew32)
