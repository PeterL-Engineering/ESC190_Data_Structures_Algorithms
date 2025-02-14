// #block [a b \'0']
// # capacity: the size of the block
// # sz: 2

#if !defined(MYSTR_H)
typedef struct mystr{
    char* block;
    int sz; // keep track of the string length
    int capacity; // keep track of the size of the block
} mystr;

#endif