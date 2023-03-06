cmake_minimum_required(VERSION 3.21)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp Game.cpp Game.h Mechanics.cpp Mechanics.h)
target_link_libraries(Pong sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)