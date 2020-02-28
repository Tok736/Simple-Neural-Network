cmake_minimum_required(VERSION 3.13)
project(Neural)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB_RECURSE CPPS
        source/*.cpp
        source/*/*.cpp
        )


add_executable(${PROJECT_NAME}
        ${CPPS} main.cpp
        )


