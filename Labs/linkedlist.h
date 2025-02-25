#ifndef linkedlist
#define linkedlist

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;
typedef struct LL{
    node *head;
    int size;
} LL;

void LL_append(LL *my_list, int new_elem);

int LL_validate_length(LL *my_list);

void LL_delete_node(LL *mylist, int index);

#endif