//
// Created by napbad on 11/11/24.
//

#include "metadata.h"

namespace dap::inter_gen
{
StructMetaData::StructMetaData(InterGenContext *context, std::string name) :
    ctx(context), name_(std::move(name))
{
}

void StructMetaData::addField(const std::string &fieldName, llvm::Type *fieldType)
{
    fields_[fieldName] = fieldType;
    fieldIndexMap_[fieldName] = fields_.size() - 1;
}

StructType *StructMetaData::getStructType() const
{
    if (!structType_)
    {
        std::vector<Type *> fieldTypes;
        fieldTypes.reserve(fields_.size());
        for (const auto &[fst, snd] : fields_)
        {
            fieldTypes.push_back(snd);
        }
        structType_ = StructType::create(LLVMCTX, fieldTypes, name_);
    }
    return structType_;
}

unsigned StructMetaData::getFieldIndex(const std::string &fieldName) const
{
    auto it = fieldIndexMap_.find(fieldName);
    if (it == fieldIndexMap_.end())
    {
        throw std::runtime_error("Field '" + fieldName + "' not found");
    }
    return it->second;
}

void StructMetaData::setStructType(StructType *type) const
{
    structType_ = type;
}

Type *StructMetaData::getFieldType(const std::string &string) const
{
    return fields_.at(string);
}

std::string StructMetaData::getName() const
{
    return name_;
}

void FunctionMetaData::genFun(const InterGenContext *ctx) const
{
    Function *fun = Function::Create(funType, GlobalValue::ExternalLinkage, name_, MODULE);


    size_t idx = 0;
    for (auto &arg : fun->args())
        arg.setName(get<0>(args[idx++]));
}
} // namespace dap::inter_gen