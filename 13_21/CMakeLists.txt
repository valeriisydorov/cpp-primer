cmake_minimum_required(VERSION 3.26)
project(13_21)

set(CMAKE_CXX_STANDARD 17)

add_executable(13_21 main.cpp
        QueryResult.cpp
        TextQuery.cpp
        RunQueries.cpp)
