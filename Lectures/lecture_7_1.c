// Things to Do for Midterm

// Go through all the pointer exercises
// Understand qsort
// Understand all the file functions fopen, fget especially
// Review linked lists (typedef struct node)

// Linked Lists Continued

#include <LL.h>

void create_node(node** p_p_n, int data){
    *p_p_n = (node*)malloc(sizeof(node));
    (*p_p_n).data = data;
    (*p_p_n).next = NULL;
}

void create_LL_from_dat(LL** p_p_LL, int* data_arr, int size){
    *p_p_LL = (LL*)malloc(sizeof(LL));
    (*p_p_LL).head = NULL;
    (*p_p_LL).sz = 0;

    int i = 0; // nodes inserted so far
    node* prev = NULL;
    while(i < size){
        node* cur;
        create_node(&cur, data_arr[i])
        if(i==0){
            (*p_p_LL).head = cur;
        }
        else{
            prev.next = cur;        
        }
        prev = cur;
        i++;
    }
}

void get_i(LL *p_LL, int i) {
    if (p_LL->sz <= i) {
        printf("ERROR: Cannot get element %d\n", i);
        exit(1);
    }
    int j = 0;
    node *cur = p_LL->head;
    while (j < i) {
        cur = cur->next;
    }
    // After the while loop runs we should be at the i-th node

    return cur->data;
}

void append(LL *p_LL, int data) {
    
    if (p_LL->head == NULL) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        p_LL->head = new_node;        
    }
    node *cur = p_LL->head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    // Now cur->next is NULL ie at the end of the LL

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    cur->next = new_node;
    p_LL->sz += 1;
}

int main() {
    int data_ints[] = {5, 10, 20, 23, 10};
    LL *p_LL;
    create_LL_from_data(&p_LL, data_unts, sizeof(data_ints)/sizeof(int));
}