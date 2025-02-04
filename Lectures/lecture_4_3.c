#include <stdio.h>
#include <stdlib.h>

int main(){
    char* str = "abc";
    // str is the address of the 'a' in the string "abc"
    // str + 1 is the address of the 'b'
    str++; // make str be equal to str+1,
    printf("%s\n", str); // bc (because str is address of b
    printf("%c\n)", *str); // just prints b ie str[0]
    printf("%c\n", *str++); // prints b because it takes the
                            // current value (str) and then increment str
    printf("%c\n", *str++); // prints c because it takes the
                            // current value (str) and then increment str    
}

char* my_strcpy2(char* dest, const char* src){

    char* dest_start = dest;
    // keep doing dest[0] = src[0]
    // increment the address dest and address src by 1
    while(*dest != '\0'){ // or while(*src) ie while it's not 
        // dest[0] = src[0]
        // dest++ and src++
        *dest++ = *src++;
        printf("dest: %ld, src: %ld \n");
    }
    *dest = *src; // we're on this line because *dest is NULL

    return dest_start;
}

char* strcat1(char* dest, const char* src){
    while(*dest){
        dest++;
    }
    my_strcpy2(dest, src);
}

struct student1{
    char name[200];
    double gpa;
};

struct student2{
    char* name;
    double gpa;
};

void create_student1(struct student1 **p_p_s1, const char* name, double gpa){

    *p_p_s1 = (struct student1*)malloc(sizeof(struct student1));
    strcpy((**p_p_s1).name, name);
    (**p_p_s1).gpa = gpa;
}

// student 2
// 1032 (name: 203759423, gpa: -2.5)

// *p_p_s1: 1032
//
//                          not a valid adress
//
//
// I currently cannot go ((**p_p_s1).name[0]) = 'x'

void create_student2v1(struct student2 **p_p_s1, const char* name, double gpa){
    *p_p_s1 = (struct student2*)malloc(sizeof(struct student2));

    // (**p_p_s1).name is not initialized (some random number)
    // problem cannot write to the random address
    // (*p_p_s1).gpa is not initialized (some random number)
    // not a problem we're about to copy local gpa to (**p_p_s1).gpa

    strcpy((**p_p_s1).name, name);
    (**p_p_s1).gpa = gpa;
}

void create_student2v1fixed(struct student2 **p_p_s1, const char* name, double gpa){
    *p_p_s1 = (struct student2*)malloc(sizeof(struct student2));

    // (**p_p_s1).name is not initialized (some random number)
    // problem cannot write to the random address
    // (*p_p_s1).gpa is not initialized (some random number)
    // not a problem we're about to copy local gpa to (**p_p_s1).gpa

    (**p_p_s1).name = (char* )malloc(sizeof(char) * (strlen(name) + 1));
    strcpy((**p_p_s1).name, name);
    (**p_p_s1).gpa = gpa;
}

void create_student2_block(struct student2 **p_p_s1, int n_students){
    (**p_p_s1).name = (struct student2* )malloc(sizeof(struct student2) * n_students);
}

int main(){
    struct student1 *p_s1;
    create_student1(&p_s1, "Mike", 3.7);
}