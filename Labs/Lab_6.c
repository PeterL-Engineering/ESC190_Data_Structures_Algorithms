#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h" // Apparently no such file in directory

// Q. 1 - 3 Found in linkedlist.c

int main () {
    LL list;
    LL_append(&list, 5);
    printf("%d\n", list.head->data);

    return 0;
}


