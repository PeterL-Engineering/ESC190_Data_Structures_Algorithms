#include <stlib.h>

int* make_arr_wrong(){
    int arr[] = {5, 6, 7};
    return arr;
}

int* make_arr_right(){
    int* arr = (int*)malloc(3 * sizeof(int));
    arr[0] = 5;
    arr[1] = 6;
    arr[2] = 7;
    return arr;
}

int main(){
    int* res1 = make_arr_right();
    res1[0] = 123;

    int* res2 = make_arr_wrong();
    res2[0] = 123; // Doesn't work because the array no longer exists
                   // after exiting the function make_arr_wrong()

    // When you're done using memeory using malloc use free() to relieve
    // memory for future use eg:
    free(res1);
    
    // int* my_block = (int*)malloc(5 * sizeof(int));
    // my_block[2] = 42;

    return 0;
}