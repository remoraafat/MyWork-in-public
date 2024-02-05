cmake_minimum_required(VERSION 3.27)
project(Pyramid)

set(CMAKE_CXX_STANDARD 14)

include_directories(..)
include_directories(include)

add_executable(BoardGame_Classes.hpp
        GameManager.cpp
        Player.cpp
        pyramid_X_O_Board.cpp
        RandomPlayer.cpp
        X_O_App.cpp
        X_O_Board.cpp
        AI_Player.cpp)