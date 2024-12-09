//
// Created by napbad on 11/26/24.
//


#include <string>
#include <unordered_map>
#include <unordered_set>

#include "src/core/common/global.h"
#include "codeGen_mechine.h"

#include "src/core/inter_gen/codegen_inter.h"
#include "src/core/inter_gen/preprocessing/includeAnaylize.h"
#include "src/core/utilities/string_util.h"


void dap::mech_gen::execGen(const std::set<inter_gen::IncludeGraphNode *>& map)
{
    std::unordered_map<inter_gen::IncludeGraphNode *, bool> visited{};
    std::unordered_set<inter_gen::IncludeGraphNode *> level{};
    std::unordered_set<inter_gen::IncludeGraphNode *> nextLevel{};

    for (auto &node : map)
    {
        level.insert(node);
    }

    while (!level.empty() || !nextLevel.empty())
    {
        for (auto &node : level)
        {
            std::string basic_string = node->getName();
            if (visited.contains(node))
            {
                continue;
            }
            programMap_d->at(node->getProgram())->genExec(node->getProgram());
            visited.insert({node, true});
            for (auto includeBy : node->getIncludedBy())
            {
                nextLevel.insert(includeBy);
            }
        }
        level.clear();
        std::swap(level, nextLevel);
    }

    std::string files = util::getStrFromVec(*filesToCompile, " ");
    files.append(" ")
         .append(buildDir)
         .append("dap/runtime/asm/_start.o ");
    system(("ld " + files + arg + " -o " + targetExecName + " ").c_str());

}

void dap::mech_gen::execGen_singleFile(inter_gen::InterGenContext *ctx, dap::parser::Program *program)
{
    ctx->genExec(program);
    std::string files = util::getStrFromVec(*filesToCompile, " ");
    files.append(" ")
         .append(buildDir)
         .append("dap/runtime/asm/_start.o ");
    system(("ld " + files + arg + " -o " + targetExecName + " ").c_str());
}