#include "parserMain.h"

namespace dap
{
std::unordered_map<parser::ProgramNode *, inter_gen::InterGenContext *> *programMap_d =
    new std::unordered_map<parser::ProgramNode *, inter_gen::InterGenContext *>();

namespace parser
{

std::string currentParsingFile = "";

void parseFile(const std::string &file)
{
    // init
    yylineno = 1;
    program = new ProgramNode();

    currentParsingFile = file;

    const auto openedFile = fopen(file.c_str(), "r");

    yyrestart(openedFile);

    yyparse();

    // store program and context info
    programMap_d->insert({program, new inter_gen::InterGenContext(file)});
}
} // namespace parser

} // namespace dap