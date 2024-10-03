cmake_minimum_required(VERSION 3.29)
project(dream)

set(CMAKE_CXX_STANDARD 20)
include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/libs/antlr4-runtime
)

find_library(LIBANTLR NAMES libantlr4-runtime.so
            HINTS /usr/lib /usr/include /usr/lib64  )

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
        src/obj/Hierarchy.cpp
        src/obj/Hierarchy.h
        src/runtime/gc/DataSource.h
        src/runtime/gc/DateSource.cpp
        src/runtime/gc/DataNode.h
        src/runtime/gc/DataNode.cpp
        src/runtime/gc/DataCopy.h
        src/runtime/gc/DataCopy.cpp
        src/runtime/class/Object.cpp
        src/runtime/class/Object.h
        src/runtime/native/thread.cpp
        src/runtime/native/thread.h
        src/common/dream_define.cpp
        src/common/dream_define.h
        src/common/dream_const.cpp
        src/common/dream_const.h
        src/runtime/native/Exception.cpp
        src/runtime/native/Exception.h
        src/runtime/reserve/d_define.h
        src/runtime/reserve/Finally.cpp
        src/runtime/reserve/Finally.h
        src/compiler/gen/ClassCodeGenerator.cpp
        src/compiler/gen/ClassCodeGenerator.h
        src/compiler/NativeConverter.cpp
        src/compiler/NativeConverter.h
        src/native/net/Socket.cpp
)

target_link_libraries(dream ${LIBANTLR})
