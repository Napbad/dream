//
// Created by napbad on 11/25/24.
//

#include "includeAnaylize.h"

#include "src/core/parser/node.h"

#include <queue>
#include <unordered_set>

namespace dap::inter_gen
{
void IncludeAnalyzer::analyze()
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
                    REPORT_ERROR("Recycling include!", __FILE__, __LINE__);
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
        // generate the package info
        parser::Stmt *pStmt = prog->stmts->stmts.at(0);
        auto *packageStmt = dynamic_cast<parser::PackageStmt *>(pStmt);
        packageStmt->codeGen(ctx);

        // generate the node
        std::string name = ctx->module->getName().str();
        auto *node = new IncludeGraphNode(name, prog);
        nodes.insert({name, node});
        roots.insert(node);
        for (const auto stmt : prog->stmts->stmts) {
            if (const auto *includeStmt = dynamic_cast<parser::IncludeStmt *>(stmt)) {
                auto *includePath = new std::string(util::getStrFromVec(*includeStmt->path->name_parts, "."));
                node->addIncludes_path(includePath);
            }
        }

        analyze();
    }
    // generate full include graph
    for (const auto &ctx : *programMap_d) {
        IncludeGraphNode *includeGraphNode = nodes.at(ctx.second->module->getName().str());
        for (const auto include : includeGraphNode->getIncludes_path()) {
            if (!nodes.contains(*include)) {
                REPORT_ERROR("Include path not found: " + *include, __FILE__, __LINE__);
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