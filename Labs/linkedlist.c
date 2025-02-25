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
        return;
    }
    else {
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
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
        i++;
    }
    
    if (i == my_list->size) {
        return 1;
    }
    
    else {
        return 0;
    }
}

void LL_delete_node(LL *mylist, int index) { 
    node *cur_node = my_list->head;
    int i = 0; // What if the index is 0?
    while (i < index) {
        cur_node = cur_node->next;
        i++;
    }

    while (cur_node->next != NULL) {
        cur_node->data = (cur_node->next)->data;
        cur_node = cur_node->next;
    }

    free(cur_node);

}

int main (){
    return 0;
}