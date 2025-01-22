#include <stdio.h>
#include <stdlib.h>

// Q. Write a program in C to find the maximum number between two numbers using a pointer. 

int max_number(int* number_1, int* number_2){
    if(*number_1 > *number_2){
        return *number_1;
    }
    else{
        return *number_2;
    }
}

// Q. Write a program in C to store n elements in an array and print the elements using a pointer. 

int main(){
    int arr_1[] = {1, 2, 3, 4, 5};
    int i = 0;
    printf("The elements you enetered are:");
    while(i < sizeof(arr_1) / sizeof(arr1[0])){
        printf("element - %d : %d\n", i, arr_1[i]);
        i++;
    }
    return 0;
}

// Q. 8. Write a program in C to print all permutations of a given string using pointers. 

void permutations(char word, int* size_of_word){
    int i = 0;
    for(i; i == size_of_word; i++){
        for()
    }
}