cmake_minimum_required(VERSION 3.30)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_CXX_STANDARD 23)

add_executable(${ProjectId} main.cpp
        Item.h
        Bag.h
        Table.h
        Table.cpp
        items/Food.h
        items/Drink.h
        items/Gadget.h
        items/Clothes.h
        items/Hygiene.h
        BruteForceKnapsack.cpp
        BruteForceKnapsack.h

)
