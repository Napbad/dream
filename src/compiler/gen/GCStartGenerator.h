//
// Created by napbad on 10/20/24.
//

#ifndef GCSTARTGENERATOR_H
#define GCSTARTGENERATOR_H
#include "CodeGenerator.h"


class GCStartGenerator final : public CodeGenerator {

public:
    [[nodiscard]] std::string generate_code() const override;
};



#endif //GCSTARTGENERATOR_H
