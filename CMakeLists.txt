cmake_minimum_required(VERSION 3.26)
project(COP_Project4)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/xcao2/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(COP_Project4
        Toolbox.cpp
        Toolbox.h
        Button.cpp
        Button.h
        Tile.cpp
        Tile.h
        GameState.cpp
        GameState.h
        minesweeper.cpp
        minesweeper.h)
target_link_libraries(COP_Project4 sfml-graphics sfml-audio)