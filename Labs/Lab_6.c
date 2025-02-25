#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h" // Apparently no such file in directory

// Q. 1 - 3 Found in linkedlist.c

int main () {
    LL *list = (LL *)malloc(sizeof(LL));
    LL_append(list, 5);
    LL_append(list, 2);
    printf("%d\n", list->head->data);
    LL_delete_node(list, 0);
    printf("%d\n", list->head->data);
    return 0;
}


