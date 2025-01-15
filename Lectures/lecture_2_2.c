void change_number(int* p_number){
    * p_number = 40;
}

int main() {
    char *s1 = "abc"; // warning: implicit conversion to char*
                      // not allowed to modify the contents of a const char*
                      // (go to address s and modify the contents there)
    // s1[0] = 'x';  will compile, but might crash at runtime
    // in C, undefined behaviour: behaviour of C that can be anything if you break the rules
    const char *s2 = "xyz"; // compiles with no warnings
                            // not allowed to modify contents at s2
                            // eaning the program won't compile
    //s2[0] = 'y';  will not compile

    s2 = "zbc"; // allowed: not changing the contents of s2
                // instead just changing s2
    
    char c = 'x';
    char* p_c = &c;
    p_c[0] = 'y'; // same as *p_c = 'y'

    // Q1. Define an integer variable a and initialize it to 42

    int a = 42;

    // Q2. Define a pointer to an integer variable p_a and initialize it to the address of a

    int* p_a = &a;

    // Q3. Using p_a and without directly using a, change the value of a to 43

    * p_a = 43;

    // Q4. Change the value of the pointer p_a to something else. Make sure that the value of a does not change

    int b = 44;
    p_a = &b;

    // Q5. Define a function that takes in a pointer to an integer and changes the integer

    change_number(&a);

    // Q7. Call the function named change_int without directly using a, but using p_a instead

    change_number(p_a);
    
    return 0;

}