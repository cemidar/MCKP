cmake_minimum_required(VERSION 3.30)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 23)

add_executable(${ProjectId} main.cpp
        Item.h
        Table.h
        Table.cpp
        BruteForceKnapsack.cpp
        BruteForceKnapsack.h
        PureBruteForce.cpp
        PureBruteForce.h

)
