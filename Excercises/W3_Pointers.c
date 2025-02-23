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

// Q. 8 Write a program in C to print all permutations of a given string using pointers. 

void change_position(char *char1, char *char2){
    char temp;
    temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

void permutations(char *word, int start, int end){
    int i = 0;
    if (start == end){
        printf("%s  ", word)
    }
    else{       
        for(i; i <= end; i++){
            change_position((word + start), (word + i));
            permutations(char, start + 1, end);
            change_position((word + start), (word + i));
        }
    }
}

// Q. 9 Write a program in C to find the largest element using Dynamic Memory Allocation.
// Test Data :
// Input total number of elements(1 to 100): 5 

int largest_element(int *arr, int sz){
    int i = 0;
    int res = -1;
    for (i; i < sz; i++){
        if (arr[i] > res){
            res = arr[i];
        }
    }

    return res;
}

// Q. 10 Write a program in C to calculate the length of a string using a pointer. 

int str_len_pointer(char *str){
    int i = 0;

    while(*(str + i) != '\0'){
        i++;
    }
    return i;
}

// Q. 11 11. Write a program in C to swap elements using call by reference.

void swap_elem(int *arr, int sz){
    int i = sz - 1;
    int last = arr[i];
    for(i; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

// Q. 18 Write a program in C to demonstrate the use of pointers to structures.
// Expected Output :

// John Alter from Court Street

typedef struct Person{
    char name[20];
    char street[40];
} person;

person *one{"John Alter", "Court Street"};

printf("%s from %s" (*one).name, (*one).street);
