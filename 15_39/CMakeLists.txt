cmake_minimum_required(VERSION 3.27)
project(15_39)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_39 main.cpp
        TextQuery.cpp
        QueryResult.cpp
        RunQueries.cpp
        Query.cpp
        WordQuery.cpp
        NotQuery.cpp
        BinaryQuery.cpp
        AndQuery.cpp
        OrQuery.cpp)
