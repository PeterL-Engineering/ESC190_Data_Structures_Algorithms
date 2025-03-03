#include "AL.h"

typedef struct cqueue {
    AL *array;
    int begin;
    int end;
} cqueue;

void initialize(cqueue **cq) {
    *cq = (cqueue *)malloc(sizeof(cqueue));
    if (!cq) {
        printf("ERROR: Could not allocate memory for queue")
        exit(1)
    }

    *cq->array = (AL *)malloc(sizeof(AL));
    if (!cq->array) {
        printf("ERROR: Could not allocate memory for AL in queue")
        exit(1)
    }

    (*cq)->begin = 0;
    (*cq)->end = 0;
}

char* cqueue_to_string(cqueue *cq) {
    if (cq->begin == cq->end) {  // Empty queue case
        return "";  // Empty string for an empty queue
    }

    // Allocate a large enough buffer for the string representation
    int buffer_size = 100;  // Arbitrary buffer size, can be dynamically adjusted
    char *result = (char *)malloc(buffer_size * sizeof(char));

    if (!result) {
        printf("ERROR: Could not allocate buffer");
        exit(1);  // Memory allocation failure
    }

    int i = cq->begin;
    int offset = 0;  // Keeps track of where to write in result

    // Loop through the circular queue
    while (1) {
        int len = snprintf(result + offset, buffer_size - offset, "%d ", cq->array[i]);
        if (len < 0) {
            free(result);
            return NULL;  // Error in snprintf
        }
        offset += len;

        if (i == cq->end) {
            break;  // Stop when reaching the end index
        }

        i = (i + 1) % cq->size;  // Wrap around if needed
    }

    return result;  // Return the string representation
}

void enqueue(cqueue *cq, int data) {
    int len_cq = cq->array->size;  

    if (cq->end != ' ') {
        AL *new_list = (AL *)malloc(sizeof(AL));
        new_list->array = (int *)malloc(sizeof(int) * len_cq * 2);
        new_list->size = len_cq;
        new_list->capacity = len_cq * 2;

        int i = cq->begin;
        int j = 0
        while (1) {
            new_list->array[j] = cq->array[i];
    
            if (i == cq->end) {
                break;  // Stop when reaching the end index
            }
            
            j++;
            i = (i + 1) % cq->size;  // Wrap around if needed
        }

        cq->end = j++;
        cq.array = new_list;
        AL_insert(cq->array, cq->end, data);
        return

    }
    else {
        if (cq->end == len_cq - 1) {
            cq->end = 0;
        } else {
            cq->end++;
        }

        // Assuming AL has a function like AL_insert(AL *al, int index, int value)
        AL_insert(cq->array, cq->end, data);
    }
}

int dequeue(cqueue *cq) {
    if (cq->begin == cq->end) {
        // Queue is empty, handle this case (return -1 or some error code)
        return -1;
    }

    int ret = cq->array->data[cq->begin];  // Assuming AL has an 'int *data' field

    // Move the begin pointer forward
    int len_cq = cq->array->size;  // Assuming AL has a 'size' field

    if (cq->begin == len_cq - 1) {
        cq->begin = 0;
    } else {
        cq->begin++;
    }

    return ret;
}
