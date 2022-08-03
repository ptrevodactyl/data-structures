cmake_minimum_required(VERSION 3.0.0)

set(This linkedList)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    linkedList.hpp
)

set(Sources
    main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)