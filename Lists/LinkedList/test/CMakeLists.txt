cmake_minimum_required(VERSION 3.0.0)

set(This linkedListTests)

set(Sources
    linkedListTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    linkedList
)

add_test(
    NAME ${This}
    COMMAND ${This}
)