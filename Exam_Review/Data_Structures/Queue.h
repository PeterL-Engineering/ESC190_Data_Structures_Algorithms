#ifndef Queue_H
#define Queue_H

#include "AL.h" 

// typedef struct ArrayList {
//     int *array;
//     int size;
//     int capacity;
// } AL;


typedef struct Queue {
    AL *list;
    int front;
} queue;

// Queue function declarations
void init(queue **p_q);
void free_queue(queue *q);
void enqueue(queue *q, int data);
void dequeue(queue *q);
int front(queue *q);  // Optional: return front element
int is_empty(queue *q); // Optional: check if empty

#endif
