#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Question 1

/*int main(){

// Question 1a)

    int* pointer_2 = NULL; //NULL == 0
    // printf("%d", *pointer_2);

// Question 1 c)

    char* filename = "b.txt";
    FILE* fp = fopen(filename, "r");

// Question 1 d)
    if (fp == NULL){
        printf("Error\n");
    }

}
*/
// Question 2

double atoif(const char* str){
    int i = 0;
    int sign = 1;
    double res1 = 0, res2 = 0;
    double count = 0;

    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;

    // Process integer part
    while (str[i] >= '0' && str[i] <= '9') {
        res1 = res1 * 10 + (str[i] - '0');
        i++;
    }

    // Process decimal part (if present)
    if (str[i] == '.') {
        i++; // Move past '.'
        while (str[i] >= '0' && str[i] <= '9') {
            res2 = res2 * 10 + (str[i] - '0');
            count++;
            i++;
        }
    }

    // Convert decimal part to fraction
    double a = 10;
    res2 = res2 / pow(a, count);

    return (res1 + res2) * sign;
    }
}

double string_sum(const char* file) {
    FILE* fp = fopen(file, "r");
    if (!fp) {
        perror("File opening failed");
        return -1; // Return error indicator
    }

    double res = 0;
    char line[1000]; // Buffer for each line

    while (fgets(line, sizeof(line), fp)) {
        char* ptr = line;

        // Find the '=' character
        while (*ptr != '=' && *ptr != '\0') {
            ptr++;
        }

        if (*ptr == '=') {
            ptr += 2; // Move past "= "
            res += atoif(ptr); // Convert to double and add
        }
    }

    fclose(fp);
    return res;
}

// Question 3

typedef struct student1{
char name[3];
int age;
} student1;

void change_name1_wrong(student1 s)
{
s.name[0] = 'b';
}

void change_name1_right_a(student1 *p_s)
{
p_s->name[0] = 'b';
}

void change_name1_right_b(student1 *p_s)
{
//strcpy(p_s->name, "b");
}

/*

wrong: The function changes the local variable s
       
righta: correctly passess in a pointer to the struct which allows
        direct change to the desired contents

rightb: correctly passess in a pointer to the struct which allows
        direct change to the desired contents. Instead of changing via array,
        simply changes by copy the source "b" to the destination "(*p_s).name"


Python function

def change_name(string, elem, change):
    L = list(string)
    L[elem - 1] = change
    return "".join(L)
*/

// void change_name(char *string, int elem, char change) {
//     if (elem > 0 && elem <= strlen(string)) {
//         string[elem - 1] = change; 
//     }
// }

int main(){
    string_sum("a.txt");
}