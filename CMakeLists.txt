cmake_minimum_required(VERSION 3.29)
project(dream)

set(CMAKE_CXX_STANDARD 20)
include_directories(
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime
        ${PROJECT_SOURCE_DIR}/src
)

find_library(LIBEDIT libedit.so /usr/lib /usr/lib64)
find_library(LIBANTLR libantlr4-runtime.so /usr/local/lib64/)

add_executable(dream src/main.cpp
        src/compiler/Compiler.cpp
        src/compiler/Compiler.h
        src/parser/DreamBaseListener.cpp
        src/parser/DreamLexer.cpp
        src/parser/DreamListener.cpp
        src/parser/DreamParser.cpp
        src/parser/DreamParser.h
        src/parser/DreamListener.h
        src/parser/DreamLexer.h
        src/parser/DreamBaseListener.h
        src/parser/DreamParserListenerCompiler.cpp
        src/parser/DreamParserListenerCompiler.h
        src/util/file_util.cpp
        src/util/file_util.h
        src/common/reserve.cpp
        src/common/reserve.h
        src/compiler/gen/CodeGenerator.cpp
        src/compiler/gen/CodeGenerator.h
        src/util/string_util.cpp
        src/util/string_util.h
)

target_link_libraries(dream ${LIBANTLR})
target_link_libraries(dream ${LIBEDIT})
