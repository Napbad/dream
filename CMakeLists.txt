cmake_minimum_required(VERSION 3.20)
project(dap)

set(CMAKE_CXX_STANDARD 20)

execute_process(
    COMMAND llvm-config --cppflags
    OUTPUT_VARIABLE LLVM_CPPFLAGS
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_compile_options(${LLVM_CPPFLAGS})
# add_compile_definitions(D_DEBUG)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Python3 COMPONENTS Interpreter REQUIRED)
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")

# 定义生成的源文件路径
set(PARSER_SOURCE "${PROJECT_SOURCE_DIR}/compiler/parser/parser.cpp")
set(TOKENS_SOURCE "${PROJECT_SOURCE_DIR}/compiler/parser/tokens.cpp")

# 使用 BISON 生成 parser.cpp
add_custom_command(
    OUTPUT ${PARSER_SOURCE}
    COMMAND ${BISON_EXECUTABLE} -o ${PARSER_SOURCE} ${PROJECT_SOURCE_DIR}/compiler/parser/parser.y
    DEPENDS ${PROJECT_SOURCE_DIR}/compiler/parser/parser.y
    COMMENT "Generating parser.cpp with Bison"
)

# 使用 FLEX 生成 tokens.cpp
add_custom_command(
    OUTPUT ${TOKENS_SOURCE}
    COMMAND ${FLEX_EXECUTABLE} -o ${TOKENS_SOURCE} ${PROJECT_SOURCE_DIR}/compiler/parser/tokens.l
    DEPENDS ${PROJECT_SOURCE_DIR}/compiler/parser/tokens.l
    COMMENT "Generating tokens.cpp with Flex"
)

add_custom_target(
        generate_parser

)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

include_directories(${PROJECT_SOURCE_DIR})

# 添加可执行文件并依赖于生成的源文件
add_executable(
    dap_main
    compiler/parser/ASTNode.cpp
    compiler/parser/ASTNode.h
    ${PARSER_SOURCE}
    ${TOKENS_SOURCE}
    compiler/main.cpp
)

target_include_directories(dap_main PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_libraries(dap_main PRIVATE LLVM pthread dl z ncurses)
