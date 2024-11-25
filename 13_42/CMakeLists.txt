cmake_minimum_required(VERSION 3.26)
project(13_42)

set(CMAKE_CXX_STANDARD 17)

add_executable(13_42 main.cpp
        StrVec.cpp
        TextQuery.cpp
        QueryResult.cpp
        RunQueries.cpp)
