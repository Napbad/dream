cmake_minimum_required(VERSION 3.5.0)
project(dream VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/c++")

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "-lstdc++")
#set(CMAKE_CXX_FLAGS "-std=c++20")

include_directories(
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime
        ${PROJECT_SOURCE_DIR}/src
)

find_library(LIBEDIT libedit.so /usr/lib /usr/lib64)
find_library(LIBANTLR libantlr4-runtime.so /usr/local/lib64/)

add_executable(dream
        src/model/val.cpp
        src/util/check.cpp
        src/util/check.h
        src/parse/DreamBaseListener.cpp
        src/parse/DreamLexer.cpp
        src/parse/DreamListener.cpp
        src/parse/DreamParser.cpp
        src/parse/DreamCommonParserListener.cpp
        src/parse/DreamCommonParserListener.h
        src/model/Package.cpp
        src/model/Package.h
        src/model/Global.cpp
        src/model/Global.h
        src/model/reserved.h
        src/util/parse_util.cpp
        src/util/parse_util.h
        src/main.cpp
        src/parse/DreamParser.h
        src/parse/DreamListener.h
        src/parse/DreamLexer.h
        src/parse/DreamBaseListener.h
        src/model/val.h
        src/model/enum.h
)

target_link_libraries(dream ${LIBANTLR})
target_link_libraries(dream ${LIBEDIT})