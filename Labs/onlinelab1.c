#include <stdio.h>

// Question 0: Make sure that you can run and compile a Hello World program in VS Code.


int main(){
    printf("Hello World");
    return 0;
}

/* Question 1: Write the function 

int linear_search(int *a, int sz, int elem)

The function returns the index of the first occurrence of the element elem in a block of ints a of size sz. Assume elem occurs in a. */

int linear_search(int* a, int sz, int elem){
    int i = 0;
    for(i; i < sz; i++){
        if (*(a + i) == elem){
            return i;}
    }
}

// Question 2: Write the following function, which reverses the block of ints arr, which is of size sz. 
// For example, if arr starts out as {5, 6, 7, 8}, it should become {8, 7, 6, 5}


void reverse_arr(int *arr, int sz){
    int temp;
    int i = 0;
    for(i; i < sz / 2; i++){
        temp = arr[i];
        arr[i] = arr[sz - i - 1];
        arr[sz - i - 1] = temp;
    }
}
