#include "Linked_List.h"
#include <stdio.h>
#include <stdlib.h>

// Linked List (LL)

// typedef struct Node {
//     int elem;
//     struct Node *next;
// } Node;

// typedef struct LinkedList {
//     Node *head;
// } LL;

Node* create_node(int elem) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->elem = elem;
    new_node->next = NULL;
    return new_node;
}

void create_list(LL **list) {
    *list = (LL *)malloc(sizeof(LL));
    (*list)->head = NULL;
}

void insert(LL *list, int elem) {
    Node *new_node = create_node(elem);

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *cur_node = list->head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
}