#include <stdio.h>

// Introduction to Project 1

typedef struct term{
    char term[200];
    double weight;
} term;

int modify_int(int* p_n){
    *p_n = 5; // Random int could be any number
}

void read_in_terms(term** term, int* p_nterms, int n){
    // Want to do something like term *p_term = (term*)malloc(100 * sizeof(term))
    // but want to modify terms to store the address of the block of terms
}

int main(){
    term t1; // A single term
    term terms1[100]; // Multiple tmers
    term* p_terms = (term*)malloc(100 * sizeof(term)); // Can return p terms
                                                       // p_terms is the address of the block
                                                       // where the terms are stored
}
/* Weighted Search

1000 aaa
500 zzz
3 ab
10 aac
40 aaz

First order via how much letters match (looking for aa)

[[1000 aaa], [40 aaz], [10 aac], [3 ab], [500 zzz]]

lowest match for "aa": 0
highest match for "aa": 2 (index in array) using binary search

atutocomplete for "aa"
[[1000 a], [40 z], [10 c]]

*/

// Valgrind: Valgrind checkes for memory leaks/invalid memory accesses

int main(){
    int* block = (int*)malloc(1000 * sizeof(int));
    printf("hi\n");
    printf("block[500] = %d\n", block[500]); // illegal since invalid access
    printf("block[1001] = %d\n", block[1001]); // illegal since invalid access

    // forget to free ie memory leak
}