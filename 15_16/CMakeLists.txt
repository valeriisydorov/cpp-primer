cmake_minimum_required(VERSION 3.27)
project(15_16)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_16 main.cpp
        Quote.cpp
        DiscQuote.cpp
        BulkQuote.cpp
        LimitQuote.cpp
        PrintTotal.cpp)
