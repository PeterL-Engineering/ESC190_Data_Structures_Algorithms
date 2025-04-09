#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int elem;
    struct Node *next;
} Node;

// Linked List structure
typedef struct LinkedList {
    Node *head;
} LL;

// Function declarations
Node* create_node(int elem);
void create_list(LL **list);
void insert(LL *list, int elem);

#endif
