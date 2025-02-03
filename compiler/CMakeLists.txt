cmake_minimum_required(VERSION 3.30)
project(compiler)

set(CMAKE_CXX_STANDARD 20)


include_directories(${PROJECT_SOURCE_DIR})

execute_process(
        COMMAND llvm-config --cppflags
        OUTPUT_VARIABLE LLVM_CPPFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_options(${LLVM_CPPFLAGS})
#add_compile_definitions(D_DEBUG)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (NOT BISON_EXECUTABLE)
    message(FATAL_ERROR "BISON executable not found")
endif ()

if (NOT FLEX_EXECUTABLE)
    message(FATAL_ERROR "FLEX executable not found")
endif ()

add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/parser/parser.cpp
        COMMAND ${BISON_EXECUTABLE} -d -o ${PROJECT_SOURCE_DIR}/parser/parser.cpp ${PROJECT_SOURCE_DIR}/parser/parser.y
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/parser.y
        COMMENT "Generating parser.cpp from parser.y"
)

add_custom_command(
        OUTPUT ${PROJECT_SOURCE_DIR}/parser/token.cpp
        COMMAND ${FLEX_EXECUTABLE} -o ${PROJECT_SOURCE_DIR}/parser/token.cpp ${PROJECT_SOURCE_DIR}/parser/token.l
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/token.l
        COMMENT "Generating parser.h from parser.l"
)

add_custom_target(
        gen_parser ALL
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/parser.cpp
        DEPENDS ${PROJECT_SOURCE_DIR}/parser/token.cpp
)


find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_executable(dap_compiler
        main.cpp
        parser/ASTNode.cpp
        parser/ASTNode.h
        parser/token.cpp
        parser/parser.hpp
        parser/parser.cpp
        utilities/data_struct_util.cpp
        utilities/data_struct_util.h
        utilities/file_util.cpp
        utilities/file_util.h
        utilities/llvm_util.cpp
        utilities/llvm_util.h
        utilities/obj_util.cpp
        utilities/obj_util.h
        utilities/string_util.cpp
        utilities/string_util.h
        common/config.cpp
        common/config.h
        common/define_d.h
        common/reserve.h
        inter_gen/codeGen_inter.cpp
        inter_gen/codeGen_inter.h
        utilities/log_util.h
        utilities/log_util.cpp
        parser/parserMain.cpp
        inter_gen/metadata.h
        inter_gen/metadata.cpp
        utilities/syntax_check_util.cpp
        utilities/syntax_check_util.h
        utilities/name_format_util.h
        utilities/name_format_util.cpp
        machine_gen/codeGen_mechine.cpp
        machine_gen/codeGen_mechine.h
        inter_gen/preprocessing/includeAnaylize.h
        inter_gen/preprocessing/includeAnaylize.cpp
        inter_gen/check/variableCheck.cpp
        inter_gen/check/variableCheck.h
        inter_gen/globalInterInfo.cpp
        inter_gen/globalInterInfo.h
)


target_link_libraries(dap_compiler PRIVATE LLVM pthread dl z ncurses)
