#include "mystr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Want: something like Python strings
//      but mutable

//writing in pseudopython
s = "abc"
s[1] = 'z' // make s be "azc"
s.append('d') // make s be azcd

// want to be able to initialize the string
// want to be able to change a character at and index
// want to be able to append


// #block [a b \'0']
// # capacity: the size of the block
// # sz: 2

#if !defined(MYSTR_H)
typedef struct mystr{
    char* block
    int sz; // keep track of the string length
    int capacity // keep track of the size of the block
} mystr;

void get char(mystr* p_s, int ind){
    if (ind < 0 || ind >= p_s -> sz){
        
    }
}

void create_string(mystr** p_p_s); // send the address of a pointer
                               // set the pointer to be 
                               // the address of a valid mystr
{
    *p_p_s = (mystr*)malloc(sizeof(mystr));
    if(*p_p_s == NULL){
        printf("ERROR: failed to create mystr");
        exit(1);
    }
    (*p_p_s)->capacity = 100;
    (*p_p_s)->block = (char*)malloc(sizeof(char)*(*p_p_s)->capacity);
    if((*p_p_s)->block == NULL){
        printf("ERROR: failed to create mystr");
        exit(1);
    }
    (*p_p_s)->block[0] = '\0';
    (*p_p_s)->sz = 0;
    // will call using create)string(&p_s)
    // p_s will get set to a valid string

}
// want to be able to initialize the string
// want to be able to change a character at and index
void set_char(mystr* p_s, int ind, char c){
    
    if((ind >= p_s->sz) || (ind < 0)){
        printf("ERROR: index %d out of bounds \n" ind);
        exit(1);
    }
    (p_s->block)[ind] = c;
} 
    // send a pointer to mystr
    // change p_s -> block contents

// want to be able to append

void append_str(mystr* p_s, const char* src){
    if(p_s->capacity < p_s->sz + strlen(src)){
        int new_capcity = (p_s->capacity + strlen(src) + 1) * 2;
                        // needs to be at least (p_s->capacity + strlen(src) + 1)
                        // might like to allocate more to not realloc all the time
        p_s->block = (char*)realloc(new_capcity * sizeof(char));
        if(p_s->block == NULL){
            printf("ERROR: string too large when appending\n");
            exit(1);
        }
        p_s->capacity = new_capcity;
        p_s->sz = strlen(src) + p_s->sz;
    }
    strcat(p_s->block, src);
    // why not just use strcat?
    // A: might not be enought space in the block;
}
                            // change p_s-> block appropriately
                            // change p_s-> capacity (possibly)
                            // change p_s-> sz (possibly)

#endif
