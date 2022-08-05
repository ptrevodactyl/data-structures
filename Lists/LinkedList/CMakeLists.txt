cmake_minimum_required(VERSION 3.0.0)

set(This linkedList)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   # Specify the commit you depend on and update it regularly.
#   URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
# )

# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(../../googletest build)

set(Headers
    linkedList.hpp
)

set(Sources
    main.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)