cmake_minimum_required(VERSION 3.29)
project(19_7)

set(CMAKE_CXX_STANDARD 20)

add_executable(
    19_7
    main.cpp
    TextQuery.cpp
    QueryResult.cpp
    Query.cpp
    WordQuery.cpp
    NotQuery.cpp
    BinaryQuery.cpp
    AndQuery.cpp
    OrQuery.cpp
)
