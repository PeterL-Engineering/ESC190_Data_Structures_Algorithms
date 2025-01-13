#include <stdio.h>
#include <stdbool.h>

// Question 1
// Connecting remotely to ecf linux computer

// Question 2

void change_value(int *p_a)
{
    *p_a = 10;
}

int main()
{
    int a = 5;
    change_value(&a);
    printf("%d\n", a);
}

/*
Python Version of Question 2

def change_value(b):
    b = 10
    return b

a = 5
change_value(a)

Similarities: Passing the variable through a function, changing via assignment
Differences: Use of pointers, and returning values from function
*/

// Question 3

void change_array_second_index(char *p_array_1)
{
    p_array_1[1] = 'c';
}

int main()
{
    char array_1[100]; // Creates an array of size 100
    array_1[0] = 'a'; // Initializes a value at index 0
    array_1[1] = 'b'; // Initializes a value at index 1
    printf("%c/n", array_1[1]); // Prints the unchanged value at index 1
    change_array_second_index(array_1); // Changes the value at index 1
    printf("%c/n", array_1[1]); // Prints the changed value at index 1
}

/*
Python Version of Question 3

def change_value_list(list):
    list[0] = 1
    return list

list = [0] * 100
change_value_list(list)
print(list[0])
*/

// Question 4

void insertion_sort(int array[], int length)
{
    int i, j, key;

    // Traverse through 1 to length of the array
    for (i = 1; i < length; i++)
    {
        key = array[i]; // Current element to be inserted
        j = i - 1;

        // Move elements of array[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key; // Place the key in its correct position
    }
}

int main()
{
    int i = 0;
    int a[5] = {2, 3, 4, 5, 6};

    // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
    // Here, i++ is the same as i = i + 1

    for(i = 0; i < 5; i++){
    printf("%d\n", a[i]);
    }

    insertion_sort(a, 5);
    for(i = 0; i < 5; i++){
    printf("%d\n", a[i]);
    }
}

// Question 5

int string_length(char* word)
{
    int i = 0;
    while (word[i] != '\0')
    {
        i++;
    }
    return i + 1;
}

// Question 6

bool match_sequence(int *arr1, int start_idx, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    if (start_idx + arr2_sz > arr1_sz) {
        return false; // Not enough elements left in arr1 to match arr2
    }
    for (unsigned long i = 0; i < arr2_sz; i++) {
        if (arr1[start_idx + i] != arr2[i]) {
            return false; // Sequence does not match
        }
    }
    return true; // Sequence matches
}

// Function to replace all occurrences of `arr2` in `arr1` with 0s
void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz) {
    if (arr2_sz == 0 || arr1_sz == 0 || arr2_sz > arr1_sz) {
        return; // No valid replacement can be performed
    }

    for (unsigned long i = 0; i <= arr1_sz - arr2_sz; i++) {
        if (match_sequence(arr1, i, arr1_sz, arr2, arr2_sz)) {
            // Replace matched sequence with 0s
            for (unsigned long j = 0; j < arr2_sz; j++) {
                arr1[i + j] = 0;
            }
            i += arr2_sz - 1; // Skip over the replaced sequence
        }
    }
}

int main() {
    int a[] = {5, 6, 7, 8, 6, 7};
    unsigned long a_sz = 6;
    int b[] = {6, 7};
    unsigned long b_sz = 2;

    printf("Original array: ");
    for (unsigned long i = 0; i < a_sz; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    seq_replace(a, a_sz, b, b_sz);

    printf("Modified array: ");
    for (unsigned long i = 0; i < a_sz; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}