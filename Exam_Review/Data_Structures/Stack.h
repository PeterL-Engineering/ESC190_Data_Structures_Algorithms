#ifndef STACK_H
#define STACK_H

#define MAX 100

// Stack structure
typedef struct Stack{
    int data[MAX];
    int top;
} Stack;

// Function declarations
void init(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif
