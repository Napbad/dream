#include "parserMain.h"

#include <fstream>

namespace dap
{
std::unordered_map<parser::ProgramNode *, inter_gen::InterGenContext *> *programMap_d =
    new std::unordered_map<parser::ProgramNode *, inter_gen::InterGenContext *>();

namespace parser
{

std::string currentParsingFile = "";

std::pair<ProgramNode *, inter_gen::InterGenContext *> parseFile(const std::string &file)
{
    // init
    yylineno = 1;
    program = new ProgramNode();

    currentParsingFile = file;

    FILE *openedFile = fopen(file.c_str(), "r");
    // freopen(file.c_str(), "r", stdin);
    // std::ifstream openedFile(file);

    yyrestart(openedFile);

    yyparse();

    // store program and context info
    auto pair = std::make_pair(program, new inter_gen::InterGenContext(file));
    programMap_d->insert(pair);
    fclose(openedFile);

    return pair;
}
} // namespace parser

} // namespace dap