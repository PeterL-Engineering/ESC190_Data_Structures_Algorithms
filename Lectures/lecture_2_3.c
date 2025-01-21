#include <stdio.h>
typedef long int sz_arr_t;

void print_array(int* array, sz_arr_t_sz){
    int i;
    for(i = 0; i < sz; i++){
        printf("%d ", arr[i])
    }
    printf("\n")
}

int main() {

    int arr[] =(5, 6, 7);
    sz_arr_t_sz = 3;
    print_array(arr, sz);

    // 1. works fine
    // 2. would not compile
    // 3. undefined behaviour: might crash at runtime

    const int a = 5; // Case 2
    a = 6;

    char* s = "abc"; // Case 1
    s = "def";

    const char* s1 = "abc"; // Means you can change the variable not the contents
    s1 = "def"; // Case 1 fine because you can change s1 completley
    s1[0] = 'x'; // Case 2 because you can't change the contents of s1

    const char* const s2 = "abc"; // Means you can't modify the variable nor the contents
    s2 = "def"; // Case 2 because you can't modify the variable

    char* const s3 = "abc"; // Means you can't modify the variable but can change the contents
    s3 = "def"; // Case 2 because you can't modify the variable
    s3[0] = 'x'; // Would be ok since we can modify the contents

    /* Understanding printf function
    
    %d: decimal
    %c: character
    %s: string
    %ld: long decimal

    printf("%d %c\n", 87, 87); Output: 87 W (ASCII binary to character)
    printf("%p\n", 87); Output: (Address of 87)
    printf("%s\n", s1+1); Output: bc (Because we start at the address of b) 
    int x = 123;
    printf("%ld\n", &x);  

    
    */
}