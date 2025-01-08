int main()
{
    int a = 42;
    long int la = 2103984203948L;
    char c = "@";  // character: a single characater
    char *s = "abs";  //"string": the address of a first character in the 
                      // sequence 'a', 'b', 's' '\0'

    char *p_c = &c;    //& (called the ampersand) means "address of"

    int arr[] = {5, 6, 7};
    printf("%d\n", arr[1]);
    
    //  Review of Pointers

    int a = 42;
    int *p_a = &a; // p_a is the address of a

    char *s = "abc"; // s is the address where the ‘a’ is

    *p_a = 43; // put 43 in address p_a
               // a becomes 43

    // How Arrays Function

    int arr[] = {6, 7, 8};
    printf("%d", *arr); // Prints 6
    // When used, array identifiers are converted
    // to the address of the first element

    printf("%d", arr[0]);

    return 0;
}