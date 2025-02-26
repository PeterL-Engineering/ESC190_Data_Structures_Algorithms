#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fgets get s a line of up to n characters from the file

int main() {
    
    int i = 0;
    int capacity = 1000;
    char *line = (char *)malloc(capacity);
    do{
        FILE *fp = fopen("lines.txt", "r");

        fgets(line, i, fp);
        printf("line 1: %s\n", line)
        i++;
        if (i == capacity) {
            capacty *= 2;
            line = realloc(line, capacity);
        }
        fclose(fp);
    } while (line(strlen(line) - 1) != '\n');
        
    return 0;
}

// Figure out how fgetc could be used to determine line size

// Example recursive question

int fib(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    return fib(n - 1) + fib(n - 2);
}

int sumfib(int n, in s) {
    // return (fib(1) + fib(2) + ...)
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }

    return fib(n) + sumfib(n - 1);
    // return fib(1) + fib(2) + ... (fib(n))
    // = fib(1) + ... + fib(n-1) + fib(n)
    // if s = fib(1) 
}