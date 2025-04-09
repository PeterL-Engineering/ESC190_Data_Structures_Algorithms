#include "AL.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct ArrayList {
//     int *array;
//     int size;
//     int capacity;
// } AL;


void create_list(AL **list) {
    *list = (AL *)malloc(sizeof(AL));
    (*list)->array = (int *)malloc(sizeof(int) * 10);
    (*list)->size = 0;
    (*list)->capacity = 10;
}

void insert(AL *list, int elem) {
    if (list->size == list->capacity) {
        int new_capacity = list->capacity * 2;
        list->array = (int *)realloc(list->array, sizeof(int) * new_capacity);
        list->capacity = new_capacity;
    }
    list->array[list->size++] = elem;
}

void print_list(AL *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

void delete_list(AL *list, int ind) {
    if (ind < 0 || ind > list->size) {
        return
    }

    for (int i = ind; i < (list->size - 1); i++) {
        list->array[i] = list->array[i + 1]; 
    }
    list->size--;
}

void destroy_list(AL *list) {
    free(list->array);
    free(list);
}
