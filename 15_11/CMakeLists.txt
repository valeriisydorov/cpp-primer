cmake_minimum_required(VERSION 3.27)
project(15_11)

set(CMAKE_CXX_STANDARD 17)

add_executable(15_11 main.cpp
        Quote.cpp
        BulkQuote.cpp
        DiscountQuote.cpp
        PrintTotal.cpp)
