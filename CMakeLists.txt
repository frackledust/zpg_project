cmake_minimum_required(VERSION 3.16)
project(zpg_project)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/headers)

set(SOURCE_FILES main.cpp ShaderManager.cpp Window.cpp App.cpp CallbackController.cpp Drawable.cpp Transformable.cpp)
set(MODEL_FILES VAO.cpp VBO.cpp DataModel.cpp)
set(DATA_FILES data/SquareColor.h data/SquareRotate.h)

link_directories(${PROJECT_SOURCE_DIR}/lib/lib-mingw-w64)
link_directories(${PROJECT_SOURCE_DIR}/lib/glew-x64)

set(CMAKE_CXX_STANDARD 14)

add_executable(zpg_project ${SOURCE_FILES} ${MODEL_FILES} ${DATA_FILES})

target_link_libraries(zpg_project glfw3 gdi32 opengl32 glew32)
