#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void LL_append(LL *my_list, int new_elem) {
    node *new_node = (node *)malloc(sizeof(node));
    if (!new_node) {
        printf("ERROR: Memory allocation failed.\n");
        return;
    }
    new_node->data = new_elem;
    new_node->next = NULL;

    if (my_list->head == NULL) {
        my_list->head = new_node;
    } else {
        node *cur_node = my_list->head;
        while (cur_node->next != NULL) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
    my_list->size++; 
}


int LL_validate_length(LL *my_list) {
    node *cur_node = my_list->head;
    int i = 0;
    while (cur_node != NULL) {
        cur_node = cur_node->next;
        i++;
    }
    
    return (i == my_list->size);
}
void LL_delete_node(LL *mylist, int index) { 
    if (mylist->head == NULL || index < 0 || index >= mylist->size) {
        printf("ERROR: Invalid index.\n");
        return;
    }

    node *cur_node = mylist->head;

    // Case 1: Delete head node
    if (index == 0) {
        mylist->head = cur_node->next;
        free(cur_node);
        mylist->size--;
        return;
    }

    // Case 2: Find the node before the one to be deleted
    int i = 0;
    node *prev_node = NULL;
    while (i < index) {
        prev_node = cur_node;
        cur_node = cur_node->next;
        i++;
    }

    // Remove the node
    prev_node->next = cur_node->next;
    free(cur_node);
    mylist->size--;
}
