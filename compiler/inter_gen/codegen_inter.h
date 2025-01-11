//
// Created by napbad on 10/24/24.
//

#ifndef CODEGEN_H
#define CODEGEN_H

#include <stack>
#include <utility>

#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>


#define LLVMCTX ctx->module->getContext()
#define MODULE ctx->module
#define BUILDER ctx->builder
namespace dap::parser
{
class Program;
class QualifiedName;
}

namespace dap::inter_gen
{
using namespace llvm;

static LLVMContext *llvmContext = new LLVMContext();

class FunctionMetaData;
class StructMetaData;
class VariableMetaData;

class ModuleMetaData;
class IncludeGraphNode;

/**
 * @brief Represents an intermediate generation block, containing a basic
 * block, return value, and local variables.
 */
class InterGenBlock
{
  public:
    BasicBlock *block{};  ///< The current basic block
    Value *returnValue{}; ///< The return value of the current block
    std::map<std::string, std::pair<Value *, VariableMetaData *>> locals{};
    std::stack<BasicBlock *> loopExitBlocks{};
    std::unordered_map<Value *, Type *> ptrValBaseTypeMapping{};
    ///< Local variables of the current block

    /**
     * @brief Constructor to initialize the basic block.
     * @param block Pointer to the basic block
     */
    explicit InterGenBlock(BasicBlock *block) : block(block)
    {
    }
};

/**
 * @brief Context class for generating intermediate representation (IR).
 */
class InterGenContext
{
    std::stack<InterGenBlock *> blocks; ///< Stack of blocks
    Function *mainFunction{};           ///< Main function
    Function *currFun = nullptr;        ///< Current function
    FunctionMetaData *currentFunMetaData = nullptr;
    bool definingStruct = false;   ///< if now defining struct
    bool definingVariable = false; ///< if now defining variable

  public:
    Module *module = nullptr;                        ///< LLVM module
    IRBuilder<> builder;                             ///< IR builder
    std::map<std::string, StructMetaData *> structs; ///< Struct metadata
    std::unordered_map<std::string, FunctionMetaData *> functions{};
    ModuleMetaData *metaData = nullptr;
    int currLine = -1;
    std::string sourcePath;
    std::string package;
    std::string fileName;
    BasicBlock* mergeBBInNestIf = nullptr;
    BasicBlock * mergeBBInNestIfSource = nullptr;
    llvm::Value * mergeBBInNestIfSrcVal = nullptr;



    FunctionMetaData *getFunMetaData(const std::string &name, const inter_gen::InterGenContext *ctx) const;
    std::pair<Value *, VariableMetaData *> getValWithMetadata(const std::string &name);
    std::pair<Value *, VariableMetaData *> getValWithMetadata(const parser::QualifiedName *name);
    FunctionMetaData *getCurrFunMetaData() const;
    void setCurrFunMetaData(inter_gen::FunctionMetaData *funMetaData);

    /**
     * @brief Constructor to initialize the module and IR builder.
     */
    explicit InterGenContext(std::string sourcePathInput)
        : builder(IRBuilder(*llvmContext)), sourcePath(std::move(std::move(sourcePathInput)))
    {
        fileName = sourcePath.substr(sourcePath.find_last_of('/') + 1);
    }

    Value *getVal(const std::string &name);

    /**
     * @brief Get the basic block of the current block.
     * @return Pointer to the current block's basic block
     */
    BasicBlock *currBlock()
    {
        return blocks.top()->block;
    }

    /**
     * @brief Get the map of local variables of the current block.
     * @return Map of local variables of the current block
     */
    std::map<std::string, std::pair<Value *, VariableMetaData *>> &locals()
    {
        return blocks.top()->locals;
    }

    /**
     * @brief Push a new basic block onto the block stack.
     * @param block Pointer to the new basic block
     */
    void pushBlock(BasicBlock *block)
    {
        blocks.push(new InterGenBlock{block});
    }

    /**
     * @brief Check if there is a current block.
     * @return True if there is a current block, otherwise false
     */
    [[nodiscard]] bool hasBlock() const
    {
        return !blocks.empty();
    }

    /**
     * @brief Pop the top block from the block stack.
     */
    void popBlock()
    {
        const InterGenBlock *top = blocks.top();
        blocks.pop();
        delete top;
    }

    /**
     * @brief Set the return value of the current block.
     * @param value Return value
     */
    void setCurrRetVal(Value *value)
    {
        blocks.top()->returnValue = value;
    }

    /**
     * @brief Set the current function.
     * @param fun Pointer to the function
     */
    void setCurrFun(Function *fun)
    {
        currFun = fun;
    }

    /**
     * @brief Get the current function.
     * @return Pointer to the current function
     */
    [[nodiscard]] Function *getCurrFun() const
    {
        return currFun;
    }

    /**
     * @brief Get the return value of the current block.
     * @return Return value of the current block
     */
    Value *getCurrRetVal()
    {
        return blocks.top()->returnValue;
    }

    /**
     * @brief Generate IR code for the given program.
     * @param program Pointer to the program
     */
    void genIR(parser::Program *program);

    /**
     * @brief Generate executable code for the given program.
     * @param program Pointer to the program
     */
    void genExec(parser::Program *program);
    /**
     * @brief Set the main function.
     * @param fun Pointer to the main function
     */
    void setMainFun(Function *fun)
    {
        mainFunction = fun;
    }

    /**
     * @brief Get the defining struct flag.
     * @return whether context is defining struct
     */
    [[nodiscard]] bool isDefStruct() const
    {
        return definingStruct;
    }

    /**
     * @brief Set the defining struct flag.
     * @param cond New value of the defining struct flag
     */
    void setDefStruct(const bool cond)
    {
        definingStruct = cond;
    }

    InterGenBlock *topBlock()
    {
        return blocks.top();
    }

    bool retValSetFlag()
    {
        return blocks.top()->returnValue != nullptr;
    }

    void setDefiningVariable(bool cond)
    {
        definingVariable = cond;
    }

    bool isDefiningVariable() const
    {
        return definingVariable;
    }

    void addPtrValBaseTypeMapping(Value *val, Type *baseType)
    {
        if (blocks.top()) {
            blocks.top()->ptrValBaseTypeMapping.insert({val, baseType});
        }
    }

    Type *getPtrValBaseTy(Value *value)
    {
        if (blocks.top() && blocks.top()->ptrValBaseTypeMapping.contains(value)) {
            return blocks.top()->ptrValBaseTypeMapping.at(value);
        }
        // REPORT_ERROR("Value not found in ptrValBaseTypeMapping", __FILE__, __LINE__);
        return nullptr;
    }

    std::string errMsg(const std::string &msg) const
    {
        return "Error at: " + sourcePath + std::to_string(currLine) + ": \n" + msg;
    }
};

void interGen_oneFile(IncludeGraphNode *node);

void interGen(const std::set<IncludeGraphNode *> &map);

} // namespace dap::inter_gen

#endif // CODEGEN_H