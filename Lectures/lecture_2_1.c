// Exercise 1

void change_a(int *p_a)
{
    // You need the address of a to change a
    // What is the variable type for "address of a"? int *
    *p_a = 42; 
}

void dont_change_a(int a)
{
    a = 43; // Sets the local variable a to 43
}
int main()
{
    int a = 5; // Sets the variable a to 5
    change_a(&a); // Passes the address of a into change_a
    printf("%d\n", a); // Prints the value of a (42)
    dont_change_a(a); // Just changes the local variable a (still 42)
    printf("%d\n", a); // Prints the value of a (42)

    int *p_a = &a;
    *p_a = 50; // Changes the value of a outside of a function
}

// Exercise 2

void change_arr0(int *p_a)
{
    *p_a = 43; // same as *(p_a+0) or p_a[0]
}
int main()
{
    int arr[3] = {5, 6, 7};
    change_arr0(arr);  // make arr[0] change.
    change(&(arr[0])); // Also makes the change
}



