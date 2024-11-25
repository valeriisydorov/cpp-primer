cmake_minimum_required(VERSION 3.26)
project(12_30)

set(CMAKE_CXX_STANDARD 17)

add_executable(12_30 main.cpp
        TextQuery.h
        QueryResult.h
        TextQuery.cpp
        QueryResult.cpp
        RunQueries.h
        RunQueries.cpp)
