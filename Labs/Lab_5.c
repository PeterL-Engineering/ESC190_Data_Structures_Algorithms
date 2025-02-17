#include <stdio.h>
#include <string.h>
#include "intlist.h"


// Allocate memory for an object of type IntList, initialize
// its data to equal the data in data_arr, and set its size
// Store the address of the new object in *p_IntList
void create_list_from_data(intlist** p_p_IntList, int* data_arr, int size){
    *p_p_IntList = (intlist*)malloc(sizeof(intlist));
    if(*p_p_IntList == NULL){
        printf("ERROR: failed to create intlist");
        exit(1);
    }
    (*p_p_IntList)->capacity = 100; // Ask Bartholomew why 100 and what is capacity
    (*p_p_IntList)->data = (int*)malloc(sizeof(int) * (*p_p_IntList)->capacity);
    if(*p_p_IntList == NULL){ // Ask Bartholomew
        printf("ERROR: failed to create intlist");
        exit(1);
    }
    (*p_p_IntList)->data[0] = '\0';
    (*p_p_IntList)->size = 0;    
}

// Append new_elem to the end of list
void list_append(intlist* p_list, int new_elem){
    if(p_list->capacity < p_list->size + 1){
        int new_capacity = (p_list->capacity + 2) * 2;
                        // needs to be at least (p_list->capacity + 2)
                        // might like to allocate more to not realloc all the time
        p_list->data = (int*)realloc(new_capacity * sizeof(int));
        if(p_list->data == NULL){
            printf("ERROR: string too large when appending\n");
            exit(1);            
        }
        p_list->capacity = new_capacity;
        p_list->size++;
    }
    (*p_list + p_list->size) = new_elem;
}

// Insert new_elem at index in list. new_elem should now be at
// location index.
// Use the function memmove to move elements of list->data as needed
// If the capacity needs to grow, use realloc to increase the capacity by
// a factor of 2
void list_insert(intlist* p_list, int new_elem, int index){
    list_append(&list, new_elem); // List now contains the new elem at the end
    memmove(index+1, index, (sizeof(int) * (p_list->size - index)));
    p_list->data[index] = new_elem;
}

// Delete the element at index index

void list_delete(intlist* p_list, int index){
    memmove(index, (index+1), (sizeof(int) * (p_list->size - index + 1)));
}

// call free as appropriate to free the memory used by list
// Note: the order in which you free list->data and list
// itself is important (how?)
void list_destroy(intlist* p_list){
    free((*p_list).data);
    free(p_list);
};

// Return the element at index index in list
int list_get(intlist* p_list, int index){
    return (*p_list).data[index];
}

#endif

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");  // Newline for better formatting
}

int main(){
    intlist** p_p_list;
    int mylist[] = {1, 2, 3};
    create_list_from_data(p_p_list, mylist, 3);
    print_array(**p_p_list->data, 3);
    list_append(*p_p_list, 5);
    print_array(**p_p_list->data, 4);
    list_insert(*p_p_list, 1, 1);
    print_array(**p_p_list->data, 5);
    list_delete(*p_p_list, 1);
    print_array(**p_p_list->data, 4);
    list_get(*p_p_list, 1);
    print_array(**p_p_list->data, 4);
    list_destroy(*p_p_list);
}
