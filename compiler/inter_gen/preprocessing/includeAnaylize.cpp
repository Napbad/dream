//
// Created by napbad on 11/25/24.
//

#include <parser/parserMain.h>
#include <queue>
#include <unordered_set>

#include "includeAnaylize.h"

#include "inter_gen/codeGen_inter.h"

#include "common/define_d.h"
#include "utilities/log_util.h"

namespace dap::inter_gen
{

void IncludeAnalyzer::analyze() const
{
    // TODO: fill the include analyze function
    for (auto root : roots) {
        std::unordered_set<IncludeGraphNode *> visited;
        std::queue<IncludeGraphNode *> includeQueue{};

        visited.insert(root);
        for (auto include : root->getIncludes()) {
            includeQueue.push(include);
            visited.insert(include);
        }

        while (!includeQueue.empty()) {
            while (!includeQueue.empty()) {
                auto include = includeQueue.front();
                if (visited.contains(include)) {
#ifdef D_DEBUG
                    util::logErr("Recycling include!", nullptr, __FILE__, __LINE__);
#else
                    util::logErr("Recycling include!", nullptr);
#endif
                }
                visited.insert(include);
                for (auto include_2level : include->getIncludes()) {
                    includeQueue.push(include_2level);
                }
                includeQueue.pop();
            }
        }
    }
}

void IncludeAnalyzer::generateGraph()
{
    for (auto &[prog, ctx] : *programMap_d) {
        // generate the node
        std::string name = ctx->module->getName().str();
        auto *node = new IncludeGraphNode(name, prog);
        nodes.insert({name, node});
        roots.insert(node);
        for (const auto package : *prog->importedPackages) {
            auto *includePath = new std::string(package->packageName->getName());
            node->addIncludes_path(includePath);
        }

        analyze();
    }
    // generate full include graph
    for (const auto &programContext : *programMap_d) {
        for (IncludeGraphNode *includeGraphNode = nodes.at(programContext.second->module->getName().str());
             const auto include : includeGraphNode->getIncludes_path()) {
            if (!nodes.contains(*include)) {
#ifdef D_DEBUG
                util::logErr("Include path not found: " + *include, programContext.second, __FILE__, __LINE__);
#else
                util::logErr("Include path not found: " + *include, ctx);
#endif

                continue;
            }
            IncludeGraphNode *includeNode = nodes.at(*include);
            includeGraphNode->addInclude(includeNode);
            includeNode->addIncludedBy(includeGraphNode);
        }
    }

    // auto newRoots = new std::set<IncludeGraphNode *>();

    // generate the root nodes where the analyzer starts
    for (auto rootIt = roots.begin(); rootIt != roots.end();) {
        auto root = *rootIt;
        std::vector<IncludeGraphNode *> includeGraphNodes = root->getIncludes();
        for (auto const includeNode : includeGraphNodes) {
            roots.insert(includeNode);
        }
        if (root->getIncludedBy().empty() || !roots.contains(root)) {
            ++rootIt;
        } else {
            rootIt = roots.erase(rootIt);
        }
    }
}
} // namespace dap::inter_gen