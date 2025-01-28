#include <stdio.h>
#define PI 3.14

// Pointers to Pointers

// Sometimes, want to change the value of a pointer inside a function

void set_to_0(int **p_p_a){
          *p_p_a = 0; // set the value at address p_p_a to 0
                             // p_p_a happens to be of type int **
                             // so *p_p_a is of type int *
}

int main(){
    /*student s;
    s.age = 20;
    s.gpa = 3.*/ //would need #include "student.h"

    int a = 42;
    int* p_a = &a;
    int** p_p_a = &p_a;
    int*** p_p_p_a = &p_p_a;

    // Review of strings

    char *name;
    strcpy(name, "Alice"); // Bad: name is not a valid address, cannot copy "Alice" there
    name = (char *)malloc(100*sizeof(char));
    strcpy(name, "Alice"); //OK now
    //name[0] = 'a'; // fine
    name = "Alice"; // OK, but cannot modify name[0]; If didn't free name, that's a memory leak
    name[0] = 'a'; // could crash

    char name[200] = "Bob"; // same as {'B', 'o', 'b', '\0'}
    strcpy(name, "Alice"); // fine, because there are are 200 spaces in name
    name = "Alice"; // Bad: cannot reassign to arrays
    strcpy(name, "Alice"); // OK
    name[0] = 'a'; // OK


    return 0;
}