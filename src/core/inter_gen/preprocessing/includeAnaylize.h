//
// Created by napbad on 11/25/24.
//

#ifndef INCLUDEANAYLIZE_H
#define INCLUDEANAYLIZE_H

#include "../../common/global.h"

#include <set>

namespace dream
{
namespace parser
{
class Program;
}

namespace inter_gen
{

class IncludeGraphNode
{
public:
    explicit IncludeGraphNode(std::string name, parser::Program *program) :
        name(name), program(program)
    {
    }

    [[nodiscard]] std::string getName() const
    {
        return name;
    }

    void addInclude(IncludeGraphNode *node)
    {
        includes.push_back(node);
    }

    void addIncludedBy(IncludeGraphNode *node)
    {
        includedBy.push_back(node);
    }

    [[nodiscard]] dream::parser::Program *getProgram() const
    {
        return program;
    }

    [[nodiscard]] std::vector<IncludeGraphNode *> getIncludedBy() const
    {
        return includedBy;
    }

    [[nodiscard]] std::vector<IncludeGraphNode *> getIncludes() const
    {
        return includes;
    }

    [[nodiscard]] std::vector<std::string *> getIncludedBy_path() const
    {
        return includedBy_path;
    }

    [[nodiscard]] std::vector<std::string *> getIncludes_path() const
    {
        return includes_path;
    }

    void addIncludedBy_path(std::string *path)
    {
        includedBy_path.push_back(path);
    }

    void addIncludes_path(std::string *path)
    {
        includes_path.push_back(path);
    }

private:
    std::string name;
    dream::parser::Program *program;
    std::vector<IncludeGraphNode *> includedBy{};
    std::vector<IncludeGraphNode *> includes{};
    std::vector<std::string *> includedBy_path{};
    std::vector<std::string *> includes_path{};
};

class IncludeAnalyzer
{
public:
    void analyze();

    [[nodiscard]] std::set<IncludeGraphNode *> getRoots() const
    {
        return roots;
    }

    void generateGraph();

private:
    std::map<std::string, IncludeGraphNode *> nodes;
    std::set<IncludeGraphNode *> roots;
};
}
} // namespace dream::inter_gen

#endif //INCLUDEANAYLIZE_H