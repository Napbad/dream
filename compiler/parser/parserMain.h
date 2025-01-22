#ifndef PARSER_MAIN_H
#define PARSER_MAIN_H

#include "inter_gen/codeGen_inter.h"
#include "parser/ASTNode.h"
#include "parser/parser.hpp"
#include <iostream>

extern void yyrestart(FILE *file);

extern dap::parser::ProgramNode *program;

extern int yylineno;

namespace dap
{
extern std::unordered_map<parser::ProgramNode *, inter_gen::InterGenContext *> *programMap_d;
}

namespace dap::parser
{

extern std::string currentParsingFile;

std::pair<ProgramNode *, inter_gen::InterGenContext *> parseFile(const std::string &file);
} // namespace dap::parser

#endif