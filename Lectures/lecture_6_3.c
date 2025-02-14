#include "LL.h"

/* Data Structures (ADTs) Continued

Each item is stored in a node that contains:
    a) A value (the data)
    b) A pointer to the next item in the list

*/

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