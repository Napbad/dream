//
// Created by napbad on 11/26/24.
//

#ifndef CODEGEN_MECHINE_H
#define CODEGEN_MECHINE_H
#include <set>
#include <string>

namespace dream
{
namespace inter_gen
{
class IncludeGraphNode;
}

namespace mech_gen
{
const std::string arg = " -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o executable";

void execGen(std::set<dream::inter_gen::IncludeGraphNode *> map);
}

}


#endif //CODEGEN_MECHINE_H