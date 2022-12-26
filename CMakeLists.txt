cmake_minimum_required(VERSION 3.16)
project(ball_simulation)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(ball_simulation main.cpp Ball.h)
target_link_libraries(ball_simulation sfml-graphics)
