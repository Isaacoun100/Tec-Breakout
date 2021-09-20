cmake_minimum_required(VERSION 3.20)
project(TecBreakout VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/cmake")

add_executable(TecBreakout src/main.cpp
        src/gui/primitive_window.cpp
        src/gui/primitive_window.h
        src/gui/include_sdl.h)

#       src/gui/game.cpp
#        src/gui/game.h
#        src/gui/text_sdl.cpp
#        src/gui/text_sdl.h
#        src/gui/object_sdl.h
#        src/gui/brick.cpp
#        src/gui/brick.h
#        src/gui/ball.cpp
#        src/gui/ball.h
#        src/gui/bar.cpp
#        src/gui/bar.h
#        src/gui/entity_sdl.cpp
#        src/gui/entity_sdl.h

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})