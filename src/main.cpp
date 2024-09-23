#include <fstream>
#include <iostream>

#include "obj/Global.h"
#include "parse/DreamParser.h"
#include "parse/DreamLexer.h"
#include "parse/DreamParserListenerCompiler.h"

using namespace std;
using namespace antlr4;

int main() {
    std::ifstream stream;
    std::string file_path = "../main.drm";

    stream.open(file_path);

    if (!stream.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    Global global;

    ANTLRInputStream inputStream(stream);
    DreamLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    DreamParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    DreamParserListenerCompiler listener_compiler(
        file_path,
        file_path.substr(file_path.find_last_of('/') + 1,
                          file_path.find(".drm") - file_path.find_last_of('/') - 1) + ".cpp",
        global);

    tree::ParseTreeWalker::DEFAULT.walk(&listener_compiler, tree);
    return 0;
}
