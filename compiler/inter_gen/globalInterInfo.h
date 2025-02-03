//
// Created by napbad on 2/3/25.
//

#ifndef GLOBALINTERINFO_H
#define GLOBALINTERINFO_H
#include <unordered_map>
#include <llvm/IR/DerivedTypes.h>

namespace dap::inter_gen
{
extern std::unordered_map<llvm::PointerType*, llvm::Type* > pointerMap;
}

#endif //GLOBALINTERINFO_H
