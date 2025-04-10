#ifndef Priority_Queue_H
#define Priority_Queue_H

#include "Array_List.h"

typedef struct prio_queue_elem {
    int value;
    int priority; // lower number = higher priority
} PQElement;

typedef struct prio_queue {
    AL *list; // dynamic array (ArrayList)
} PQ;

// Creates a priority queue
void create_prio_queue(PQ **p_p_queue);

// Destroys the priority queue
void destroy_queue(PQ *p_q);

// Inserts an element with the given value and priority into the priority queue
void insert(PQ *p_q, int value, int priority);

// Extracts the element with the minimum priority (highest priority)
int extract_min(PQ *p_q);

#endif
