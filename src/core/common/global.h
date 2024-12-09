//
// Created by napbad on 11/19/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H
#include "../inter_gen/metadata.h"

#include <llvm/IR/Value.h>
#include <map>
#include <stack>

namespace dap::parser
{
class Program;
}

namespace llvm
{
class AllocaInst;
}

using namespace llvm;


/**
 * struct heap_d - Describes the structure of the heap
 * @heapStart_d: Pointer to the start of the heap
 * @heapEnd_d: Pointer to the end of the heap
 * @heapPtr_d: Current pointer position in the heap
 * @heapSize_d: Size of the heap
 *
 * This structure is used to describe the state of the heap during program execution, including the start and end positions, current pointer position, and size of the heap.
 */
struct heap_d
{
    Value *heapStart_d;
    Value *heapEnd_d;
    Value *heapPtr_d;
    Value *heapSize_d;
};

// Pointer to the global heap structure, used to share heap information throughout the program
extern heap_d *globalHeap_d;

// Map that associates pointers with allocation instructions, used to track getelementptr instructions and their corresponding allocation instructions
extern std::map<Value *, AllocaInst *> *gepMapping_d;

// Map that associates basic blocks with return values, used to track the return value of each basic block
extern std::map<BasicBlock *, Value *> *blockMappingRet_d;

// Stack that stores expected dereference types, used to track type information
extern std::stack<Type *> *expectDerefType_d;

// Map that stores metadata for each module
extern std::unordered_map<std::string, dap::inter_gen::ModuleMetaData *> *moduleMetadataMap_d;

// this is a map that stores the program that the parser parsed and the Context it corresponds to
extern std::unordered_map<dap::parser::Program *, dap::inter_gen::InterGenContext *> *programMap_d;

// files that will be the arguments of ld
extern std::vector<std::string> *filesToCompile;

// directory where the build files will be stored
extern std::string buildDir;

// name of the executable file
extern std::string targetExecName;

dap::inter_gen::ModuleMetaData *getModuleMetaData(const std::string &name);

#define globalHeap globalHeap_d
#define gepMapping gepMapping_d
#endif // GLOBAL_H