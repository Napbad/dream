//
// Created by napbad on 11/22/24.
//

#ifndef DERIVED_TYPE_H
#define DERIVED_TYPE_H
#include <llvm/IR/DerivedTypes.h>

// A class representing a pointer type, derived from the Type class
class PointerType_d : public Type
{
  public:
    // Returns the base type of the pointer
    [[nodiscard]] Type *getBaseTy() const
    {
        return baseTy;
    }

    // Static method to create and return a new PointerType_d instance
    static PointerType_d *get(LLVMContext &ctx, Type *baseTy)
    {
        return new PointerType_d(ctx, baseTy);
    }

    // Checks if the given Type is an instance of PointerType_d
    static bool classof(const Type *t)
    {
        return t->getTypeID() == PointerTyID;
    }

  private:
    // LLVM pointer type, used for interaction with the LLVM type system
    PointerType *ptrTy;
    // The base type of the pointer
    Type *baseTy;

    // Constructor to initialize a PointerType_d instance
    explicit PointerType_d(LLVMContext &ctx, Type *baseTy) : Type(ctx, PointerTyID), baseTy(baseTy)
    {
        ptrTy = PointerType::get(baseTy, 0);
    }
};

#endif // DERIVED_TYPE_H
