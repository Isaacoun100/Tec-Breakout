cmake_minimum_required(VERSION 3.20)
project(Tec-Breakout VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${${PROJECT_NAME}_SOURCE_DIR}/cmake")

add_executable(Tec-Breakout
        src/main.cpp
        src/gui/primitive_window.cpp
        src/gui/primitive_window.h
        src/socket/SocketServer.cpp
        src/socket/SocketServer.h
        src/socket/SocketClient.cpp
        src/socket/SocketClient.h
        src/login/StartClient.cpp
        src/login/StartClient.h
        src/login/StartServer.cpp
        src/login/StartServer.h
        src/login/Login.cpp
        src/login/Login.h
        src/gui/game.cpp
        src/gui/game.h
        src/gui/text_sdl.cpp
        src/gui/text_sdl.h
        src/gui/object_sdl.h
        src/gui/brick.cpp
        src/gui/brick.h
        src/gui/ball.cpp
        src/gui/ball.h
        src/gui/bar.cpp
        src/gui/bar.h
        src/gui/entity_sdl.cpp
        src/gui/entity_sdl.h
        src/gui/player_gui.cpp
        src/gui/player_gui.h
        src/temp/ReadWrite.cpp 
        src/temp/ReadWrite.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_FLAGS -pthread)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})