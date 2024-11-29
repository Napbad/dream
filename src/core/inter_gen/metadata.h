//
// Created by napbad on 11/11/24.
//

#ifndef STRUCTMETADATA_H
#define STRUCTMETADATA_H

#include "codegen_inter.h"

#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Type.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace llvm;

namespace dream::inter_gen
{
class InterGenContext;

class StructMetaData
{
public:
    explicit StructMetaData(InterGenContext *context, std::string name);

    // add Field
    void addField(const std::string &fieldName, Type *fieldType);

    // Get StructType
    StructType *getStructType() const;

    // get index by name
    unsigned getFieldIndex(const std::string &fieldName) const;

    void setStructType(StructType *type) const;

    Type *getFieldType(const std::string &string) const;

    std::string getName() const;

private:
    InterGenContext *ctx;
    std::string name_;
    std::unordered_map<std::string, Type *> fields_;
    std::unordered_map<std::string, unsigned> fieldIndexMap_;
    mutable StructType *structType_ = nullptr;
};

class FunctionMetaData
{
public:

    void genFun(const InterGenContext *ctx) const;

    FunctionMetaData(std::string name, FunctionType *funType) :
        name_(std::move(name)), funType(funType)
    {
    }

    void addArg(const std::string &name, Value *arg, Type *type)
    {
        args.emplace_back(name, arg, type);
    }

    [[nodiscard]] std::string getName() const
    {
        return name_;
    }

    [[nodiscard]] FunctionType *getType() const
    {
        return funType;
    }

    [[nodiscard]] Type *getArgType(const int index) const
    {
        return std::get<2>(args[index]);
    }

    [[nodiscard]] Type *getArgType(const std::string &argName) const
    {
        for (auto &arg : args)
        {
            if (get<0>(arg) == argName)
            {
                return std::get<2>(arg);
            }
        }
        return nullptr;
    }

    [[nodiscard]] Value *getArg(const int index) const
    {
        return std::get<1>(args[index]);
    }

    [[nodiscard]] Value *getArg(const std::string &argName) const
    {
        for (auto &arg : args)
        {
            if (get<0>(arg) == argName)
            {
                return std::get<1>(arg);
            }
        }
        return nullptr;
    }

private:
    std::string name_;
    FunctionType *funType;
    std::vector<std::tuple<std::string, Value *, Type *>> args;
};

class ModuleMetaData
{
public:
    explicit ModuleMetaData(Module *module) :
        module_(module)
    {

    }

    // Add a structure metadata to the module
    void addStruct(StructMetaData *structMeta)
    {
        structs.push_back(structMeta);
        structMap[structMeta->getName()] = structMeta;
    }

    // Get a structure metadata by name
    StructMetaData *getStruct(const std::string &name) const
    {
        const auto it = structMap.find(name);
        if (it != structMap.end())
        {
            return it->second;
        }
        return nullptr;
    }

    // Add a function metadata to the module
    void addFunction(FunctionMetaData *funcMeta)
    {
        functions.push_back(funcMeta);
        functionMap[funcMeta->getName()] = funcMeta;
    }

    // Get a function metadata by name
    FunctionMetaData *getFunction(const std::string &name) const
    {
        auto it = functionMap.find(name);
        if (it != functionMap.end())
        {
            return it->second;
        }
        return nullptr;
    }

    // Add a global value to the module
    void addGlobalValue(Value *val)
    {
        globalVals.push_back(val);
    }

    // Get all global values in the module
    const std::vector<Value *> &getGlobalValues() const
    {
        return globalVals;
    }

    // Add a global variable to the module
    void addGlobalVariable(GlobalVariable *var)
    {
        globalVar.push_back(var);
    }

    // Get all global variables in the module
    const std::vector<GlobalVariable *> &getGlobalVariables() const
    {
        return globalVar;
    }

    // Set the module name
    void setModuleName(const std::string &name)
    {
        moduleName = name;
    }

    // Get the module name
    const std::string &getModuleName() const
    {
        return moduleName;
    }

    // Set the module path
    void setModulePath(const std::string &path)
    {
        modulePath = path;
    }

    // Get the module path
    const std::string &getModulePath() const
    {
        return modulePath;
    }

    // Set the module source code
    void setModuleSource(const std::string &source)
    {
        moduleSource = source;
    }

    // Get the module source code
    const std::string &getModuleSource() const
    {
        return moduleSource;
    }

    std::vector<FunctionMetaData *> getFunctions()
    {
        return functions;
    }

    Module* getModule() const
    {
        return module_;
    };;

private:
    std::vector<StructMetaData *> structs; // List of structure metadata
    std::vector<FunctionMetaData *> functions; // List of function metadata
    std::unordered_map<std::string, StructMetaData *> structMap; // Map of structure metadata by name
    std::unordered_map<std::string, FunctionMetaData *> functionMap; // Map of function metadata by name
    std::vector<Value *> globalVals; // List of global values
    std::vector<GlobalVariable *> globalVar; // List of global variables
    std::string moduleName; // Name of the module
    std::string modulePath; // Path of the module
    std::string moduleSource; // Source code of the module
    Module *module_ = nullptr;
};
} // namespace dream::inter_gen

#endif // STRUCTMETADATA_H