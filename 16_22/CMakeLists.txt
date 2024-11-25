cmake_minimum_required(VERSION 3.27)
project(16_22)

set(CMAKE_CXX_STANDARD 17)

add_executable(16_22 main.cpp
        TextQuery.cpp
        RunQueries.cpp
        QueryResult.cpp)
