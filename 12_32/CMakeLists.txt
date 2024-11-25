cmake_minimum_required(VERSION 3.26)
project(12_32)

set(CMAKE_CXX_STANDARD 17)

add_executable(12_32 main.cpp
        QueryResult.cpp
        TextQuery.cpp
        RunQueries.cpp
        StrBlobPtr.cpp
        StrBlob.cpp)
