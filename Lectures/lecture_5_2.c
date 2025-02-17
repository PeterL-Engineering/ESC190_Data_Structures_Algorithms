#include <stdio.h>

void change_arr(int* p_block){
    p_block_2 = 42
}

void change_name(student21* p_s, char* name){
    strcpy((*p_s).name, name)
}

int main18(){
    // Pointer Exercises

    // Q. 18 Create a malloc-allocated block of memory that can store 3 integers. 
    // Store the address in the variable p_block. Then use change_arr to change the value at index 2

    int* p_block = (int*)malloc(3 * sizeof(int));
    char_arr(p_block);
    return 0;

}

typedef struct student21{
    char name[30];
    int age;
} student21

int main22(){
    // Q. 21 Create an object of type student, with char name[1000] and int age, and initialize it

    student21 s = ("Roger", 41);
    // s.name = "Jennifer" // CANNOT do: can initialize arrays like this but not change

    // Q. 22 Change the name of the student to "Jennifer"

    strcpy(s.name, "Jennifer")
    // Manual strcpy
    char* src = "Jennifer";
    int i = 0;
    while(*src){
        (s.name)[i] = *src; // same as (*(s.name + i)) = *src
        src++;
        i++;
    }
    (s.name)[i] = '\0';

    // Q. 23 Change the age of the student to 21

    s.age = 21;

    // Q. 24 Create a pointer to the student and initialize it 
    student21* p_s = &s;

    // Q. 25 Change the name of the student to Jenny using p_s

    strcpy((*p_s).name, "Jenny");
    strcpy(p_s->name, "Jenny");

    // Q. 26 Change the age of the student using p_s
    (*p_s).age = 5;

    // Q. 27 Change the name of student using a function

    student21 s2 = ("Bob", 50);
    student21* p_s2 = &s2;
    change_name(p_s2, "Alice");

    // Q. 28 Using the same function but don't use p_s

    change_name(&s2, "Poo Poo");

    return 0;
}

int main(){

    // Question 32

    student22 students[5];
    // Want to change the name/age of student [2]
    change_name(&(students[2]) "Nicole is smelly");
    change_name(students + 2, "Nicole is very smelly");
}
