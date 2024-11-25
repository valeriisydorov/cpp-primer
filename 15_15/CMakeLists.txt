cmake_minimum_required(VERSION 3.27)
project(15_15)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_15 main.cpp
        Quote.cpp
        DiscQuote.cpp
        BulkQuote.cpp
        PrintTotal.cpp)
