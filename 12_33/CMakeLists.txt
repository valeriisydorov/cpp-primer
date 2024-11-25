cmake_minimum_required(VERSION 3.26)
project(12_33)

set(CMAKE_CXX_STANDARD 17)

add_executable(12_33 main.cpp
        QueryResult.cpp
        TextQuery.cpp
        RunQueries.cpp)
