//
// Created by napbad on 11/26/24.
//

#ifndef CODEGEN_MECHINE_H
#define CODEGEN_MECHINE_H

#include "src/core/common/global.h"
#include "src/core/inter_gen/preprocessing/includeAnaylize.h"
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
extern std::unordered_map<inter_gen::IncludeGraphNode *, bool> visited;

const std::string arg = " -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2 ";

void execGen(const std::set<dap::inter_gen::IncludeGraphNode *> &map);

void execGen_singleFile(inter_gen::InterGenContext *ctx, dap::parser::Program *program);

void genExecToOneFile(inter_gen::IncludeGraphNode *node);
} // namespace mech_gen

} // namespace dap

#endif // CODEGEN_MECHINE_H