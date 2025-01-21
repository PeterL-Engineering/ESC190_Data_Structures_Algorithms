#include <stdlib.h>
#include <stdio.h>

// Review of typedef
/*
    Typedef is a way to give names to types in C
    typedef int arr_sz_t;
    arr_sz_t sz_of_arr = 15;

    We can use typedef in conjuction with struct eg.
    struct student{
     char name[200];
     char number[11]; // why 11? so that C knows when to stop (ID is 10 digits)
     double GPA; // Note that the ID is stored as a char because C variables type int
                    cannot be extremely long
    };

    if we use typedef struct student and call the compound variable student
    then when we want to call struct student we would only have to use student
    instead of struct student

    int main()
    {
        // access fields of a struct using .
        struct student s1 = {“John Doe”, “1234567890”, 3.3};
        printf(“%s %f\n”, s1.name, s1.GPA);

        student* p_s1 = &s1;
        printf("%s %f\n", (*p_s1).name, (*p_s1).GPA);

        Instead of doing (*a).b you can do a->b

        printf("%s %f\n", *p_s1->name, *p_s1->GPA);

    }
*/

// Finding the length of a string

int my_strlen(char* s){
    int cur_i = 0;
    while(s[cur_i] != '\0'){
        cur_i++;
    }
    return cur_i;
}

// WANT: recusive my_strlen
// base case: if s[0] = '\0', can return 0
// recusive step: my_strlen(s) = 1 + my_strlen(s+1)

int my_strlen_rec(char* s){
    if(s[0] = '\0'){
        return 0;
    }
    else{
        return 1 + my_strlen_rec(s+1);
    }
}

int main(){
    char s[] = 'abc';
    printf("%d\n", my_strlen(s));  
}

// Memory Allocation

// When you return the address of an array from a function
// It will no longer exist when you exit, ie an address of nothing

int *block_int = (int *)malloc(sizeof(int) * 150); // allocate space for 150 integers
                                                   // malloc returns the address of 
                                                   // element 0
                                                   // cast the address to int *

block_int[7] = 42; 
*(block_int + 7) = 42;   // REMINDER: those are the same
                         // block + 7 gets to the right location in the memory table
                         // because C knows how many cells ints take up

// Size of function

sizeof(int) // usually 4 bytes
sizeof(char) // always 1 byte
sizeof(char *) // usually addresses take up 8 bytes 
                      // NOT the length of a string/array
sizeof(int *)    // usually addresses take up 8 bytes
                      // NOT the length of a string/array
