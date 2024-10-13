#include <fstream>
#include <iostream>

#include "obj/Global.h"
#include "parse/DreamParser.h"
#include "parse/DreamLexer.h"
#include "parse/DreamParserListenerCompiler.h"
#include "util/file_util.h"
#include "util/response_util.h"

using namespace std;
using namespace antlr4;

int main(int args, char** argv)
{
    std::string input_dir = "../dream";
    for (int i = 1; i < args; ++i) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
            case 'd':
                print(cout, "DEBUG mode compiling \n", file_util::FileColor::GREEN);
                global_flag_is_debug = true;
                break;
            default:
                response_util::report_error("Invalid argument input at: " + std::string(argv[i]));
                return 1;
            }
        } else if (std::string(argv[i]).find('/') != std::string::npos)
        {
            // argv[i] is a directory to compile
            input_dir = argv[i];
        }
        else {
            response_util::report_error("Invalid argument format: " + std::string(argv[i]));
            return 1;
        }
    }

    std::ifstream stream;

    std::string runtime_src_dir = "../src/runtime";
    std::string runtime_dest_dir = "../build/runtime";
    std::string native_src_dir = "../src/natives";
    std::string native_dest_dir = "../build/natives";

    std::string main_fun_file_path;
    bool is_main_fun_file_found = false;

    file_util::copy_directory(runtime_src_dir, runtime_dest_dir);
    file_util::copy_directory(native_src_dir, native_dest_dir);

    for (std::vector<std::string> files_in_dir = file_util::get_all_files_in_dir("../build/runtime");
         auto& file : files_in_dir)
    {
        global->add_file_compile(file);
    }


    for (std::vector<std::string> files = file_util::get_all_files_in_dir(input_dir);
        auto& file_path : files)
    {

        if (file_path.ends_with("/main.drm"))
        {
            if (is_main_fun_file_found)
            {
                response_util::report_error("Multiple main.drm files found, first found in file: "
                    + main_fun_file_path, file_path, 0);
                return 1;
            }
            main_fun_file_path = file_path;
            is_main_fun_file_found = true;
            continue;   
        }

        if (global_flag_is_debug)
            dbg_print(cout, "handling: " + file_path + "\n", file_util::FileColor::WHITE);
        stream.open(file_path);

        if (!stream.is_open())
        {
            cout << "Error opening file" << endl;
            return 1;
        }

        ANTLRInputStream inputStream(stream);
        DreamLexer lexer(&inputStream);
        CommonTokenStream tokens(&lexer);
        DreamParser parser(&tokens);

        tree::ParseTree* tree = parser.program();


        DreamParserListenerCompiler listener_compiler(
            file_path,
            file_path.substr(file_path.find_last_of('/') + 1,
                             file_path.find(".drm") - file_path.find_last_of('/') - 1) + ".cpp",
            global);

        tree::ParseTreeWalker::DEFAULT.walk(&listener_compiler, tree);
        stream.close();
    }

    stream.open(main_fun_file_path);

    if (!stream.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    ANTLRInputStream inputStream(stream);
    DreamLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    DreamParser parser(&tokens);

    tree::ParseTree* tree = parser.program();


    DreamParserListenerCompiler listener_compiler(
        main_fun_file_path,
        main_fun_file_path.substr(main_fun_file_path.find_last_of('/') + 1,
                         main_fun_file_path.find(".drm") - main_fun_file_path.find_last_of('/') - 1) + ".cpp",
        global);

    tree::ParseTreeWalker::DEFAULT.walk(&listener_compiler, tree);
    stream.close();

    file_util::delete_directory(native_dest_dir);

    return 0;
}
