#include <stdio.h>
#include <stdlib.h>

char *strcat(char*str1, const char* str2){
    int i = 0;
    while(str1[i] != NULL){
        i++;
    }

    int j = 0;
    while(str2[j] != NULL){
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = NULL;

    return str1;
}

char* strcpy(char* dest, const char* src){
    
    while(*src != NULL){
        *dest = *src;
        dest++;
        src++;
    }
    
    int i = 0;
    while(src[i] != NULL){
        dest[i] = src[i];
        i++;
    }
    dest[i] = NULL;
    return dest;
}

void change_int(int* p_x){ // Simple example that does the same thing as create_str
    *p_x = 123;
}

void create_str(char** p_str, int sz){
    *p_str = (char*)malloc(sz * sizeof(char)); // change str
    if(*p_str == NULL){
        printf("ERROR: out of memory, download more RAM");
        exit(1);
    }
}

int main(){
// Realloc

// Can resize blocks of memory using realloc

char *str = (char *)malloc(100 * sizeof(char));
// want to make more space

str = (char *)realloc(str, 200 * sizeof(char));

// In the event that there is not sufficient memory, use exit
/*
 char *block = malloc(10000000);
if (block == NULL){
    printf("Out of memory\n");
    exit(1); // exit terminates the program. the 1 is sent to the operating system
    }*/

// Example Create String

    char* str;
    create_str(&str, 200); // make str be the address of the first element
                      // of a string
                      // HAVE to send in &str to be abel to change the value of str
    // if I wanted to change str[0] I would just pass str
    strcpy(str, "Mike");
    printf("Name: %s\n", str);

    int a = 42;
    int b = a++; // the value of a++ is the old value of a
                    // the effect of a++ is to increment a by 1
                    // the value of b is now 42, the value of a is 43
    int c = ++b; // the value of ++b is the new value of b (i.e., b+1)
                    // the effect of ++b is to increment b by 1
                    // the value of b and c is now 43
    
    /*
    *str2 = *str1;  // copies the value from address str1 to address str2
    *str2++ = *str1++; // copies values and then increments addresses
    */

    return 0;
}
