cmake_minimum_required(VERSION 3.26)
project(14_30)

set(CMAKE_CXX_STANDARD 17)

add_executable(14_30 main.cpp
        StrBlob.cpp
        StrBlobPtr.cpp
        ConstStrBlobPtr.cpp
)
