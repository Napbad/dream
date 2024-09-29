// created by napbad

#ifndef DATANODE_H
#define DATANODE_H

enum DataType
{
    SHORT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    BOOL,
    LONG,
    STRING,
    LONGLONG,
    UCHAR,
    UINT,
    ULONG,
    ULONGLONG
};

union Data
{
    short *_short;
    int *_int;
    char *_char;
    float *_float;
    double *_double;
    bool *_bool;
    long *_long;
    char *_string;
    long long *_longlong;
    unsigned char *_uchar;
    unsigned int *_uint;
    unsigned long *_ulong;
    unsigned long long *_ulonglong;
};


class DataNode
{
private:
    Data _data{};
    int _type;

    DataNode(Data data, int type);
public:
    ~DataNode();

    static DataNode *create(int type);

    // Create integer type DataNode
    static DataNode *create_int(int val, int type);

    // Create long integer type DataNode
    static DataNode *create_long(long val, int type);

    // Create double precision floating point type DataNode
    static DataNode *create_double(double val, int type);

    // Create short integer type DataNode
    static DataNode *create_short(short val, int type);

    // Create character type DataNode
    static DataNode *create_char(char val, int type);

    // Create boolean type DataNode
    static DataNode *create_bool(bool val, int type);

    // Create long long integer type DataNode
    static DataNode *create_longlong(long long val, int type);

    // Create unsigned character type DataNode
    static DataNode *create_uchar(unsigned char val, int type);

    // Create unsigned integer type DataNode
    static DataNode *create_uint(unsigned int val, int type);

    // Create unsigned long integer type DataNode
    static DataNode *create_ulong(unsigned long val, int type);

    // Create unsigned long long integer type DataNode
    static DataNode *create_ulonglong(unsigned long long val, int type);


    [[nodiscard]] int type() const;
};

#endif