//
// Created by napbad on 9/18/24.
//

#ifndef ASTNODE_H
#define ASTNODE_H
#include <vector>

enum NodeType {
    VAR_DECL,

};

union ast_value {
    bool _bit;
    bool _bool;

    char _char;

    double _double;
    float _float;

    short _short;
    int _int;
    long _long;
    long long _longlong;

    unsigned short _ushort;
    unsigned int _uint;
    unsigned long _ulong;
    unsigned long long _ulonglong;

    char* _string;
};

class ASTNode {
    int _node_type;
    ASTNode *_parent;
    std::vector<ASTNode *> *_children;
    ast_value _value;
};



#endif //ASTNODE_H
