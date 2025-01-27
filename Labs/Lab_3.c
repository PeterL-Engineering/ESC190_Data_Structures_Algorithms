#include <stdio.h>
#include <string.h>

// Question 1

void set_int1(int x){
    x = 42;
}
void set_int2(int* p_x){
    *p_x = 42;
}

int main(){
    int x = 5;
    set_int1(x);
    set_int2(&x);
    return 0;
}

// set_int1 doesn't change x because we pass a copy of x
// meaning we just change the copy and not the real x
// set_int2 changes x because we pass in where x lives in the memory

// Question 2

typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void print_student_info(student1* p_s){
    print("%s, %ld, %d", (*p_s).name, (*p_s).student_number, (*p_s).year);
}

int main(){
    student1 s1 = {"Bob", 1234567899, 2025};
    print_student_info(&s1);
    return 0;
}

// Question 3 a)

void set_default_name(student1 *p_s){
    strcpy((*p_s).name, "default name");
}

// Question 3 b)

void set_default_name_wrong(student1 s){
    // For Q.3 this would never work since we're passing in a copy
}

// Question 4

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1 *)malloc(sizeof(student1) * n_students);
}

// Question 5

void set_name(char* name, student1 *s){
    // Copy the name into the student structure safely
    strncpy(s->name, name, sizeof(s->name) - 1);

    // Ensure the name is null-terminated
    s->name[sizeof(s->name) - 1] = '\0';
}

// Question 6

void destroy_block1(student1 *p_p_s){
    free(*p_p_s);
}

// Question 7

typedef struct student2{
    char* name;
    char* student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_studnets){
    int i = 0;
    for(i; i == num_students; i++){
        *(p_p_s)[i].name = '0'
        *(p_p_s)[i].student_number = '0'
    }
}

// Question 8

void set_name2(student2 *s, char* name){
    
    *name = (char*)malloc(sizeof(*name));

}