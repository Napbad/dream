cmake_minimum_required(VERSION 3.26)
project(dap)

set(CMAKE_CXX_STANDARD 23)

add_executable(
    dap
    ast.cpp
    ast.hpp
    parser.hpp
    parser.cpp
    lex.cpp
)


