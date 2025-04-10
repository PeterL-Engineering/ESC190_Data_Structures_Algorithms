#include "Priortiy_Queue.h"

'''
typedef struct prio_queue_elem {
    int value;
    int priority; // lower number = higher priority
} PQElement;

typedef struct prio_queue {
    AL *list; // dynamic array (ArrayList)
} PQ;
'''

// Creates a priority queue
void create_prio_queue(PQ **p_p_queue) {
    *p_p_queue = malloc(sizeof(PQ));
    create_list(&(*p_p_queue)->list);
}

// Destroys the priority queue
void destroy_queue(PQ *p_q) {
    destroy_list(p_q->list);
    free(p_q);
}

// Inserts an element with the given value and priority into the priority queue
void insert(PQ *p_q, int value, int priority) {
    PQElement new_element = { value, priority };
    
    // Find the correct index to insert the element in sorted order
    int insert_index = p_q->list->size;
    while (insert_index > 0 && p_q->list->array[insert_index - 1].priority > priority) {
        insert_index--;
    }

    // Shift elements to the right to make space for the new element
    for (int i = p_q->list->size; i > insert_index; i--) {
        p_q->list->array[i] = p_q->list->array[i - 1];
    }

    // Insert the new element
    p_q->list->array[insert_index] = new_element;
    p_q->list->size++;
}

// Extracts the element with the minimum priority (highest priority)
int extract_min(PQ *p_q) {
    int min_index = 0;

    // Linear search to find the minimum priority element
    for (int i = 1; i < p_q->list->size; i++) {
        if (p_q->list->array[i].priority < p_q->list->array[min_index].priority) {
            min_index = i;
        }
    }

    // Get the min value
    int min_value = p_q->list->array[min_index].value;

    // Remove the element from the list by shifting all elements after it
    for (int i = min_index; i < p_q->list->size - 1; i++) {
        p_q->list->array[i] = p_q->list->array[i + 1];
    }
    p_q->list->size--; // Reduce the size after removal

    return min_value;
}
