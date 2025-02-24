#include <linkedlist.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void LL_append(LL *my_list, int new_elem) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_elem;
    new_node->next = NULL;

    if (my_list->head == NULL) {
        my_list->head = new_node;
        return;
    }

    node *cur_node = my_list->head;

    int i = 0;
    while (i < my_list->sz) {
        cur_node = cur_node->next;
    }
    cur_node->next = new_node;
    my_list->size++;
}

int main (){
    return 0;
}