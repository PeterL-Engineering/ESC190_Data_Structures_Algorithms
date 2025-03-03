#if !defined(Q)
#include <stdlib.h>
#include "AL.h"
#define Q

typedef struct queue {
    AL * list;
} queue;

void create_queue(queue **p_q);
void destroy_queue(queue *q);

void enqueue(queue);
void dequeue(queue);


#endif