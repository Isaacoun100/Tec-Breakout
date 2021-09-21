cmake_minimum_required(VERSION 3.20)
project(Tec-Breakout VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Tec-Breakout src/main.cpp src/gui/example_gui.cpp src/logic/example_logic.cpp src/gui/example_gui.h src/logic/example_logic.h src/socket/SocketServer.cpp src/socket/SocketServer.h src/socket/SocketClient.cpp src/socket/SocketClient.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_FLAGS -pthread)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} )