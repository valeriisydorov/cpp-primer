cmake_minimum_required(VERSION 3.27)
project(15_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_5 main.cpp
        Quote.cpp
        BulkQuote.cpp
        PrintTotal.cpp)
