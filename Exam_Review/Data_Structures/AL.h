#ifndef AL_H
#define AL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
    int *array;
    int size;
    int capacity;
} AL;

void create_list(AL **list);
void insert(AL *list, int elem);
void print_list(AL *list);
void delete_list(AL *list);

#endif
