// created by napnad


#include "DataNode.h"

DataNode *DataNode::create(int type){
    Data data{};

    switch (type) {
    case BOOL:
        data._bool = new bool;
        break;
    
    case CHAR:
        data._char = new char;
        break;

    case SHORT:
        data._short = new short;
        break;

    case INT:
        data._int = new int;
        break;

    case FLOAT:
        data._float = new float;
        break;

    case DOUBLE:
        data._double = new double;
        break;

    case LONG:
        data._long = new long;
        break;

    case STRING:
        data._string = new char; 
        break;

    case LONGLONG:
        data._longlong = new long long;
        break;

    case UCHAR:
        data._uchar = new unsigned char;
        break;

    case UINT:
        data._uint = new unsigned int; 
        break;

    case ULONG:
        data._ulong = new unsigned long;
        break;

    case ULONGLONG:
        data._ulonglong = new unsigned long long;
        break;

    default:
        return nullptr;
    }

    return new DataNode(data, type);
}



int DataNode::type() const
{
    return _type;
}


// Create integer type DataNode
DataNode *DataNode::create_int(const int val, const int type) {
    DataNode *node = create(type);
    if (node && type == INT) {
        *node->_data._int = val;
    }
    return node;
}

// Create long integer type DataNode
DataNode *DataNode::create_long(const long val, const int type) {
    DataNode *node = create(type);
    if (node && type == LONG) {
        *node->_data._long = val;
    }
    return node;
}

// Create double precision floating point type DataNode
DataNode *DataNode::create_double(const double val, const int type) {
    DataNode *node = create(type);
    if (node && type == DOUBLE) {
        *node->_data._double = val;
    }
    return node;
}

// Create short integer type DataNode
DataNode *DataNode::create_short(const short val, const int type) {
    DataNode *node = create(type);
    if (node && type == SHORT) {
        *node->_data._short = val;
    }
    return node;
}

// Create character type DataNode
DataNode *DataNode::create_char(const char val, const int type) {
    DataNode *node = create(type);
    if (node && type == CHAR) {
        *node->_data._char = val;
    }
    return node;
}

// Create boolean type DataNode
DataNode *DataNode::create_bool(const bool val, const int type) {
    DataNode *node = create(type);
    if (node && type == BOOL) {
        *node->_data._bool = val;
    }
    return node;
}

// Create long long integer type DataNode
DataNode *DataNode::create_longlong(const long long val, const int type) {
    DataNode *node = create(type);
    if (node && type == LONGLONG) {
        *node->_data._longlong = val;
    }
    return node;
}

// Create unsigned character type DataNode
DataNode *DataNode::create_uchar(const unsigned char val, const int type) {
    DataNode *node = create(type);
    if (node && type == UCHAR) {
        *node->_data._uchar = val;
    }
    return node;
}

// Create unsigned integer type DataNode
DataNode *DataNode::create_uint(const unsigned int val, const int type) {
    DataNode *node = create(type);
    if (node && type == UINT) {
        *node->_data._uint = val;
    }
    return node;
}

// Create unsigned long integer type DataNode
DataNode *DataNode::create_ulong(const unsigned long val, const int type) {
    DataNode *node = create(type);
    if (node && type == ULONG) {
        *node->_data._ulong = val;
    }
    return node;
}

// Create unsigned long long integer type DataNode
DataNode *DataNode::create_ulonglong(const unsigned long long val, const int type) {
    DataNode *node = create(type);
    if (node && type == ULONGLONG) {
        *node->_data._ulonglong = val;
    }
    return node;
}

DataNode::DataNode(const Data data, const int type)
{
    _data = data;
    _type = type;
}

DataNode::~DataNode() {
    switch (_type) {
    case BOOL:
        delete _data._bool;
        break;

    case CHAR:
        delete _data._char;
        break;

    case SHORT:
        delete _data._short;
        break;

    case INT:
        delete _data._int;
        break;

    case FLOAT:
        delete _data._float;
        break;

    case DOUBLE:
        delete _data._double;
        break;

    case LONG:
        delete _data._long;
        break;

    case STRING:
        delete _data._string;
        break;

    case LONGLONG:
        delete _data._longlong;
        break;

    case UCHAR:
        delete _data._uchar;
        break;

    case UINT:
        delete _data._uint; 
        break;

    case ULONG:
        delete _data._ulong;
        break;

    case ULONGLONG:
        delete _data._ulonglong;
        break;

    default:
        break;
    }
}
