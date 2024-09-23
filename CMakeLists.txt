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
        src/parse/DreamBaseListener.cpp
        src/parse/DreamLexer.cpp
        src/parse/DreamListener.cpp
        src/parse/DreamParser.cpp
        src/parse/DreamParser.h
        src/parse/DreamListener.h
        src/parse/DreamLexer.h
        src/parse/DreamBaseListener.h
        src/parse/DreamParserListenerCompiler.cpp
        src/parse/DreamParserListenerCompiler.h
        src/util/file_util.cpp
        src/util/file_util.h
        src/common/reserve.cpp
        src/common/reserve.h
        src/compiler/gen/CodeGenerator.cpp
        src/compiler/gen/CodeGenerator.h
        src/util/string_util.cpp
        src/util/string_util.h
        src/parse/DreamParserListenerCompiler.cpp
        src/parse/DreamParserListenerCompiler.h
        src/obj/Global.cpp
        src/obj/Global.h
        src/util/response_util.cpp
        src/util/response_util.h
)

target_link_libraries(dream ${LIBANTLR})
target_link_libraries(dream ${LIBEDIT})
