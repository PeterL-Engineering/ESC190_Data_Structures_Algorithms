int main() // function named main
           // doesn't take any parameters

{
    int n; // declaring the variable nm of type int
    n = 25; // setting the value of n to 25
    printf("%d\n", n); // prints the value of n
    char c = '@';
    int *p_a = 0; // p_a is a type of int*

    p_a = &n; // & means "address of"
              // RHS: the address where the variable n is stored
              // put the RHS in the LHS

    int m = *p_a; // When on the RHS, * means get the valule at the address
                  // *p_a is the value at address p_a
                  // m is now 25 

    char *s = "abc"; // s is the address where 'a' is
                     // s + 1 is the address where 'b' is ...
                     // s + 3 is the address where '\0' is
    printf("The string is: %n", s); // prints abc
    printf("The NULL is %c", s[3]); // prints the NULL
    return 0;
}

// body of the function is inside curly braces
// every statement must end with a semicolon