cmake_minimum_required(VERSION 3.20)
project(Tec-Breakout VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Tec-Breakout main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})