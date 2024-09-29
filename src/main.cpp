#include <fstream>
#include <iostream>

#include "obj/Global.h"
#include "parse/DreamParser.h"
#include "parse/DreamLexer.h"
#include "parse/DreamParserListenerCompiler.h"
#include "util/file_util.h"

using namespace std;
using namespace antlr4;

int main() {
    std::ifstream stream;
    std::string file_path = "../dream/main.drm";
    Global global;


    stream.open(file_path);

    if (!stream.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }


    ANTLRInputStream inputStream(stream);
    DreamLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    DreamParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    file_util::copy_directory("../src/runtime", "../build/runtime");

    DreamParserListenerCompiler listener_compiler(
        file_path,
        file_path.substr(file_path.find_last_of('/') + 1,
                          file_path.find(".drm") - file_path.find_last_of('/') - 1) + ".cpp",
        global);

    tree::ParseTreeWalker::DEFAULT.walk(&listener_compiler, tree);
    stream.close();

    file_path = "../dream/temp.drm";
    stream.open(file_path);

    if (!stream.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    ANTLRInputStream inputStream1(stream);
    DreamLexer lexer1(&inputStream1);
    CommonTokenStream tokens1(&lexer1);
    DreamParser parser1(&tokens1);

    tree::ParseTree *tree1 = parser1.program();
    DreamParserListenerCompiler listener_compiler1(
    file_path,
    file_path.substr(file_path.find_last_of('/') + 1,
                      file_path.find(".drm") - file_path.find_last_of('/') - 1) + ".cpp",
    global);

    tree::ParseTreeWalker::DEFAULT.walk(&listener_compiler1, tree1);

    return 0;
}
