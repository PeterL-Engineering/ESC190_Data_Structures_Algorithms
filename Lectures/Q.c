#include "Q.h"

// void create_queue(queue **p_q);
// void destroy_queue(queue *q);

// void enqueue(queue *q, int data);
// void dequeue(queue *q);

void create_queue(queue **p_q) {
    (*p_q) = malloc(sizeof(queue));
    create_list(&(*p_q)->list);
}

void destroy_queue(queue *q) {
    destroy_list(q->list);
    free(q);
}

void enqueue(queue *q, int data) {
    insert_list(q->list, data);
}

// dequeue get element at index 0, remove it, and return it

void dequeue(queue *q) {
    int ret = q->list->array[0];
    delete_list(q->list, 0);
    return ret;
}

