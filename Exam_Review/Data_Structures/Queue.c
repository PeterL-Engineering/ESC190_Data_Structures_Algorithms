#include "Array_List.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct ArrayList {
//     int *array;
//     int size;
//     int capacity;
// } AL;


// Queue (Q)

void init(queue **p_q) {
    *p_q = malloc(sizeof(queue));
    create_list(&(*p_q)->list);
}

void free_queue(queue *q) {
    destroy_list(q->list);
    free(q);
}

void enqueue(queue *q, int data) {
    insert_list(q->list, data);
}

void dequeue(queue *q) {
    int res = q->list->array[0];
    delete_list(q->list, 0);
    return res;
}

int is_empty(queue *q) {
    if (q->size == 0) {
        return 1;
    }
    return 0;
}
