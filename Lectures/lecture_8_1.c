#include "LL.h"
#include "AL.h"
#include "Q.h"
#include <stdio.h>

int main() {
    LL *list;
    create_list(&list);
    insert_list(list, 1);
    insert_list(list, 1);
    insert_list(list, 1);
    insert_list(list, 1);
    insert_list(list, 1);
    print_list(list);
    delete_list(list, 0);
    print_list(list);
    return 0;

    queue *q;
    create_queue(&q);
    enqueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 2);
    prinf("%d\n", dequeue(q));
    prinf("%d\n", dequeue(q));
    destroy_queue(q);
}

// If you have a linked list: 1->2->3->4
//               array list : [1, 2, 3, 4, 5]

// append ("insert") 
    // For the array list, can access index 5 immediately but you need to reallocate 
    // the whole array and move it. Meaning O(n) where n is num elements

    // For the linked list, can append to the beginning O(1) just make the head point
    // to the new node, and new node point to the old head

// -----------------

// Queue (Abstract Data Type)
    // A list with FIFO (First in first out) operations 
    // No random access (ie. ability to get element by index)

// Queue Operations
    // Enqueue: Add an element to the end of the queue
    // Dequeue: Delete the first element of the queue

    // Ex. Enquque 5, enqueue 6, enqueue 1 -> 5 6 1 
    //     dequeue = 5 -> 6 1; dequeue = 6 -> 1
