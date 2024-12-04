cmake_minimum_required(VERSION 3.26)
project(dap)

set(CMAKE_CXX_STANDARD 23)

execute_process(
        COMMAND llvm-config --cppflags
        OUTPUT_VARIABLE LLVM_CPPFLAGS
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_compile_options(${LLVM_CPPFLAGS})
add_compile_definitions(D_DEBUG)

add_executable(dap_main src/core/main.cpp
        src/core/inter_gen/codegen_inter.cpp
        src/core/inter_gen/codegen_inter.h
        src/core/parser/parser.cpp
        src/core/parser/parser.hpp
        src/core/parser/tokens.cpp
        src/core/utilities/file_util.h
        src/core/utilities/file_util.cpp
        src/core/common/reserve.h
        src/core/utilities/string_util.h
        src/core/utilities/string_util.cpp
        src/core/parser/node.h
        src/core/parser/node.cpp
        src/core/utilities/llvm_util.cpp
        src/core/utilities/llvm_util.h
        src/core/inter_gen/funGen_sys.cpp
        src/core/inter_gen/funGen_sys.h
        src/core/inter_gen/Hierarchy.cpp
        src/core/inter_gen/Hierarchy.h
        src/core/inter_gen/metadata.cpp
        src/core/inter_gen/metadata.h
        src/core/gc/DGC.cpp
        src/core/gc/DGC.h
        src/core/inter_gen/basicElementGen_d.cpp
        src/core/inter_gen/basicElementGen_d.h
        src/core/inter_gen/objectGen_d.cpp
        src/core/inter_gen/objectGen_d.h
        src/core/common/define_d.h
        src/core/common/macro_def.h
        src/core/utilities/data_struct_util.cpp
        src/core/utilities/data_struct_util.h
        src/core/utilities/obj_util.cpp
        src/core/utilities/obj_util.h
        src/core/common/global.h
        src/core/common/global.cpp
        src/core/common/derived_type.h
        src/core/parser/node_meta_data.cpp
        src/core/parser/node_meta_data.h
        src/core/inter_gen/preprocessing/includeAnaylize.cpp
        src/core/inter_gen/preprocessing/includeAnaylize.h
        src/core/mechine_code_gen/codeGen_mechine.cpp
        src/core/mechine_code_gen/codeGen_mechine.h
)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

target_link_libraries(dap_main PRIVATE LLVM pthread dl z ncurses)


# add_executable(dap_test
#         src/core/inter_gen/codegen_inter.cpp
#         src/core/inter_gen/codegen_inter.h
#         src/core/parser/parser.cpp
#         src/core/parser/parser.hpp
#         src/core/parser/tokens.cpp
#         src/core/utilities/file_util.h
#         src/core/utilities/file_util.cpp
#         src/core/common/reserve.h
#         src/core/utilities/string_util.h
#         src/core/utilities/string_util.cpp
#         src/core/parser/node.h
#         src/core/parser/node.cpp
#         src/core/utilities/llvm_util.cpp
#         src/core/utilities/llvm_util.h
#         src/core/inter_gen/funGen_sys.cpp
#         src/core/inter_gen/funGen_sys.h
#         src/core/inter_gen/Hierarchy.cpp
#         src/core/inter_gen/Hierarchy.h
#         src/core/inter_gen/metadata.cpp
#         src/core/inter_gen/metadata.h
#         src/core/gc/DGC.cpp
#         src/core/gc/DGC.h
#         src/core/inter_gen/basicElementGen_d.cpp
#         src/core/inter_gen/basicElementGen_d.h
#         src/core/inter_gen/objectGen_d.cpp
#         src/core/inter_gen/objectGen_d.h
#         src/core/common/define_d.h
#         src/core/common/macro_def.h
#         src/core/utilities/data_struct_util.cpp
#         src/core/utilities/data_struct_util.h
#         src/core/utilities/obj_util.cpp
#         src/core/utilities/obj_util.h
#         src/core/common/global.h
#         src/core/common/derived_type.h
#         src/core/parser/node_meta_data.cpp
#         src/core/parser/node_meta_data.h
#         src/core/inter_gen/preprocessing/includeAnaylize.cpp
#         src/core/inter_gen/preprocessing/includeAnaylize.h
#         src/core/mechine_code_gen/codeGen_mechine.cpp
#         src/core/mechine_code_gen/codeGen_mechine.h
# )
#
# target_link_libraries(dap_test PRIVATE LLVM pthread dl z ncurses)
#