//
// Created by napbad on 11/26/24.
//

#ifndef CODEGEN_MECHINE_H
#define CODEGEN_MECHINE_H
#include "../common/global.h"

#include <set>
#include <string>

namespace dap
{
namespace inter_gen
{
class IncludeGraphNode;
}

namespace mech_gen
{
const std::string arg = " -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 ";

void execGen(std::set<dap::inter_gen::IncludeGraphNode *> map);
void execGen_singleFile(inter_gen::InterGenContext * ctx, dap::parser::Program * program);
}

}


#endif //CODEGEN_MECHINE_H