// Changing the value of a variable

int f(int *p_a)
{
    *p_a = 43; // Go to the cell with the address of p_a
               // and change the value to 43
}

int main()
{
    int a = 42;
    f(&a); // Take the address of a and pass it into the function f
           // See text in the function f
}

// Examples of Pointer Arithmetic

int main()
{
    int arr[] = {6, 7, 8};
    printf("%p\n", arr + 1); // Printed the address of the 7 within the array
    printf("%ld\n", arr);    // The same address just in decimal format
    printf("%ld\n", arr + 1); // The prior address plus four
}