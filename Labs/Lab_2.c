#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Question 1: Write a function that takes in an address of the first element
// of a block of ints, and sets all the elements at even indices to 0. For example,
// if the input block is {5, 6, 7, 8}, it should be change to {0, 6, 0, 8}.

void set_even_to_zero(int* block, int size){
    int i = 0;
    for(i = 0; i <= size; i++){
        if (block[i] % 2 == 0){
            block[i] = 0;
        }
    }
    return block;
}

// Question 2: Implement two versions of the string.h function strcat: 
// https://www.programiz.com/c-programming/ library-function/string.h/strcat .
// In one version, use the index i to access elements of strings.
// In another version, only use pointer arithmetic.

char strcat_index(char* destination, const char* source){
    int i = 0;
    while(destination[i] != '\0'){
        i++;
    }
    int j = 0;
    while(source[j] != '\0'){
        destination[i + j] = source[j];
        j++;
    }
    destination[i + j] = '\0';
    return destination;
}

char strcat_arith(char* destination, const char* source){
    int i = 0;
    while(*(destination + i) != '\0'){
        i++;
    }
    int j = 0;
    while(*(source + j) != '\0'){
        *(destination + i + j) = *(source + j);
        j++;
    }
    *(destination + i + j) = '\0';
    return destination;
}

int main(){
    char str1[100] = "hello", str2[] = "world";


    
    return 0;
}

// Question 3: Implement a version of strcmp recursively. Name the 
//function my strcmp rec. See the description of strcmp here: 
// https://www.programiz.com/c-programming/library-function/string.h/strcmp

int my_strcmp_rec(char* word1, char* word2){
    if(*word1 == '\0' && *word2 == '\0'){
        return 0;
    }
    if(*word1 == *word2){
        return my_strcmp_rec((word1 + 1), (word2+ 1)); 
    }
    return(*(word1) > *(word2));
}

// s1 == s2 compares the values of the addresses
// *s1 == *s2 compares the first character at that address


// Question 4: See Lab_2.py

// Question 5: The C library function atoi converts a string to an integer. 
// Write your own version of the function, with the signature int my_atoi(char *str)
// Hints:
// The function isdigit (defined in <ctype.h>) can be used to tell if a character is a digit
// You can convert a digit c to an integer value using c-’0’. For example, ’5’-’0’ is 5 since the digits
// ’0’, ’1’, ’2’, ’3’, ’4’, ’5’ appear in sequence in the ASCII table

int my_atoi(char * str){
    int i = 0;
    int res = 0;

    while(*(str + i) != '\0'){
        if(isdigit(*(str + i))){
            res = res * 10 + *(str + i) - '0';
        }
        i++;
    }
    return res;
}