// Combining Strings and Structs
typedef struct student{
    char name[200];
    double gpa;
} student;
/*
student s1 make_student1(char* name, double gpa){
    student1 s1;
    s1.name = name;
    s1.gpa = gpa;
    return s1;
}

student s2 make_student2(char* name, double gpa){
    
    // Creates a new block of ememory to store the name
    // Store the address of the block at s1.name
    // Copy the name to the adress at s1.name
    student2 s2;
    s2.name = (char*)malloc(strlen(name) + 1)
    strcpy(s2.name, name)
    s2.gpa = gpa;
    return s2;

    // Now we can modify the name since we used malloc
}

student s3 make_student3(char* name, double gpa){
    // s.2name is an array: already allocated
    // cannot reassign to arrays
    // can write to arrays
    student3 s3;
    strcpy(s3.name, name);
    s3.gpa = gpa;
    return s3
}
*/
int main(){
//    s1 = make_studnet1("Mike", 3.7);
}