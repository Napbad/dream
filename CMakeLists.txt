cmake_minimum_required(VERSION 3.5.0)
project(dream VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_COMPILER "/usr/bin/c++")

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime
        ${PROJECT_SOURCE_DIR}/src
)

find_library(LIBEDIT libedit.so /usr/lib /usr/lib64)
find_library(LIBANTLR libantlr4-runtime.so /usr/local/lib64/)

add_executable(dream
        src/obj/val.cpp
        src/util/check.cpp
        src/util/check.h
        src/parse/DreamBaseListener.cpp
        src/parse/DreamLexer.cpp
        src/parse/DreamListener.cpp
        src/parse/DreamParser.cpp
        src/parse/DreamParserListenerRunner.cpp
        src/parse/DreamParserListenerRunner.h
        src/obj/Package.cpp
        src/obj/Package.h
        src/obj/Global.cpp
        src/obj/Global.h
        src/common/reserved.h
        src/util/parse_util.cpp
        src/util/parse_util.h
        src/main.cpp
        src/parse/DreamParser.h
        src/parse/DreamListener.h
        src/parse/DreamLexer.h
        src/parse/DreamBaseListener.h
        src/obj/val.h
        src/common/enum.h
        src/common/reserved.cpp
        src/gc/DataSource.cpp
        src/gc/DataSource.h
        src/gc/gc.cpp
        src/gc/gc.h
        src/parse/DreamParserListener.cpp
        src/parse/DreamParserListener.h
)

target_link_libraries(dream ${LIBANTLR})
target_link_libraries(dream ${LIBEDIT})