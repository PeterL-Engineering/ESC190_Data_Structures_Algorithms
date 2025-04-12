// Q. 1

double fact(int n) {
    if (n < 0) {
        return -1; // or throw an error
    }

    double res = 1;

    while (n > 1) {
        res *= n--;
    }

    return res;
}

// Q. 2

#include <string.h>

void replace_ws(char *s) {
    const char *target = "winter";
    const char *replacement = "summer";
    int len = strlen(target);

    for (int i = 0; s[i] != '\0'; i++) {
        // Check for match
        if (strncmp(&s[i], target, len) == 0) {
            // Replace characters
            for (int j = 0; j < len; j++) {
                s[i + j] = replacement[j];
            }
            i += len - 1;  // Skip ahead
        }
    }
}

// Q. 3

int list_cmp(int *arr1, int* arr2) {
    if (arr1[0] == '\0' && arr2[0] == '\0') {
        return 1;
    }
    
    if (arr1[0] != arr2[0]) {
        return 0;
    }

    return list_cmp((arr1 + 1), (arr2 + 1));
}

// Q. 4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct LL {
    node *head;
    int size;
} Ll;

void LL_append(LL *mylist, int new_val, int i) {
    if (i < 0 || i > mylist->size) {
        printf("Index out of bounds.\n");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_val;
    new_node->next = NULL;

    if (i == 0) {
        new_node->next = mylist->head;
        mylist->head = new_node;
    } else {
        node *cur = mylist->head;
        for (int j = 0; j < i - 1; j++) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }

    mylist->size++;
}