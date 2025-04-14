'''
Q. 1

a)
    - Header files help you separate declaration and implementation of function/DSA
    - Helps make code more resuable by allowing you to import into other files

    - Easier deubgging and code organization
    - Optimized code compilation (only the modified source files need to be recompiled)

    - Significantly reduce development time by providing read-made functions
    - Portable across different compilers and platforms

b) return value = 0.75

c) 
    - Saves memory and can be used when you know the value will not be negative
    - In a signed bit, the most significant bit (MSB) is reserved for the sign

d) 
    - Incorrect assignment for b
    - Function returns local pointer

'''

// Q. 2

typedef struct Node {
    int data;
    struct Node *next;
} Node;

float averageLinkedList(Node *L, int *n) {
    if (L == NULL) {
        *n = 0;
        return 0;
    }

    float sum = averageLinkedList(L->next, n);
    *n += 1;
    return sum + L->data;
}

// Q. 3

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int sumBST(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (root->data >= 10) {
        sum += root->data;
    }

    sum += sumBST(root->left);
    sum += sumBST(root->right);

    return sum;
}

// Q. 4

'''
The following functions are available to you

Stack * initStack();
void push(struct Stack * s, struct Data d);
Data pop(struct Stack * s);
int isEmpty(struct Stack * s);
void deleteStack(struct Stack * s);
'''

#define NODES 6

typedef struct adjMat {
    int matrix[NODES][NODES];
    int vNodes[NODES];
} adjMat;

typedef struct Data {
    int val;
} Data;

void dfTraversal(adjMat *aM, int n) {
    int cur, neighbour;

    // Mark all nodes unvisited
    for (int i = 0; i < NODES; i++) {
        aM->vNodes[i] = 0;
    }

    Stack *S;
    initStack(&S);
    push(S, n);
    printf("Visited: %d\n", n);
    aM->vNodes[n] = 1;

    while (!isEmpty(S)) {
        cur = pop(S);

        // Loop over all possible neighbours
        for (int i = 0; i < NODES; i++) {
            if (aM->matrix[cur][i] != 0 && aM->vNodes[i] == 0) {
                push(S, i);
                aM->vNodes[i] = 1;
                printf("Visited: %d\n", i);
            }
        }
    }
}