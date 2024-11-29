//
// Created by napbad on 11/24/24.
//

#include "node_meta_data.h"
namespace dream::parser
{
std::unordered_map<Node *, parser::NodeMetadata *> *nodeMetadataMapping =
    new std::unordered_map<Node *, parser::NodeMetadata *>;

}
