//
// Created by napbad on 11/19/24.
//

#ifndef GLOBAL_H
#define GLOBAL_H
#include "../inter_gen/metadata.h"

#include <llvm/IR/Value.h>
#include <map>
#include <stack>

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

extern std::unordered_map<std::string, dream::inter_gen::ModuleMetaData *> *moduleMetadataMap_d;

extern std::unordered_map<dream::parser::Program*, dream::inter_gen::InterGenContext *> *programMap_d;

extern std::vector<std::string> *filesToCompile;

extern std::unordered_map<Value *, Value *> *ptrArrSizeMap_d;

#define globalHeap globalHeap_d
#define gepMapping gepMapping_d

#endif // GLOBAL_H