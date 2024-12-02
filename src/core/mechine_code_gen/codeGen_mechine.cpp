//
// Created by napbad on 11/26/24.
//

#include "codeGen_mechine.h"
#include "../inter_gen/preprocessing/includeAnaylize.h"

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "../common/global.h"



void dap::mech_gen::execGen(std::set<inter_gen::IncludeGraphNode *> map)
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
    files.append(" ./build/dap/runtime/asm/_start.o ");
    system(("ld " + files + arg).c_str());
}