// Q. 1

double fact(int n) {
    if (n < 0) {
        return -1; // or throw an error
    }

    double res = 1;

    while (n > 1) {
        res *= n--;
    }

    return res;
}

// Q. 2

#include <string.h>

void replace_ws(char *s) {
    const char *target = "winter";
    const char *replacement = "summer";
    int len = strlen(target);

    for (int i = 0; s[i] != '\0'; i++) {
        // Check for match
        if (strncmp(&s[i], target, len) == 0) {
            // Replace characters
            for (int j = 0; j < len; j++) {
                s[i + j] = replacement[j];
            }
            i += len - 1;  // Skip ahead
        }
    }
}

// Q. 3

int list_cmp(int *arr1, int* arr2) {
    if (arr1[0] == '\0' && arr2[0] == '\0') {
        return 1;
    }
    
    if (arr1[0] != arr2[0]) {
        return 0;
    }

    return list_cmp((arr1 + 1), (arr2 + 1));
}

// Q. 4

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct LL {
    node *head;
    int size;
} Ll;

void LL_append(LL *mylist, int new_val, int i) {
    if (i < 0 || i > mylist->size) {
        printf("Index out of bounds.\n");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_val;
    new_node->next = NULL;

    if (i == 0) {
        new_node->next = mylist->head;
        mylist->head = new_node;
    } else {
        node *cur = mylist->head;
        for (int j = 0; j < i - 1; j++) {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }

    mylist->size++;
}

// Q. 5

typedef struct Matrix {
    int **matrix;
    int num_cols;
    int num_rows;
} Matrix;

// Initialize a matrix of size n x m
void init(Matrix **matrix, int n, int m) {
    *matrix = (Matrix *)malloc(sizeof(Matrix));
    (*matrix)->num_rows = n;
    (*matrix)->num_cols = m;

    (*matrix)->matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*matrix)->matrix[i] = (int *)malloc(m * sizeof(int));
    }
}

// Check if (i, j) is within bounds (0-based indexing)
int in_bounds(Matrix *matrix, int i, int j) {
    if (i < 0 || i >= matrix->num_rows || j < 0 || j >= matrix->num_cols) {
        printf("ERROR: Index exceeds matrix size\n");
        return 0;
    }
    return 1;
}

// Get element at (i, j) using 1-based indexing
int get_elem(Matrix *matrix, int i, int j) {
    if (!in_bounds(matrix, i - 1, j - 1)) {
        return 0;
    }
    return matrix->matrix[i - 1][j - 1];
}

// Set element at (i, j) using 1-based indexing
void set_elem(Matrix *matrix, int i, int j, int elem) {
    if (!in_bounds(matrix, i - 1, j - 1)) {
        return;
    }
    matrix->matrix[i - 1][j - 1] = elem;
}

// Add two matrices and return the result
Matrix *matrix_sum(Matrix *matrix1, Matrix *matrix2) {
    if (matrix1->num_rows != matrix2->num_rows || matrix1->num_cols != matrix2->num_cols) {
        printf("ERROR: Matrix sizes do not match!\n");
        return NULL;
    }

    Matrix *res;
    init(&res, matrix1->num_rows, matrix1->num_cols);

    for (int i = 0; i < matrix1->num_rows; i++) {
        for (int j = 0; j < matrix1->num_cols; j++) {
            int sum = get_elem(matrix1, i + 1, j + 1) + get_elem(matrix2, i + 1, j + 1);
            set_elem(res, i + 1, j + 1, sum);
        }
    }

    return res;
}

// Free memory used by matrix
void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->num_rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

// Q. 6

typedef struct PQ_elem {
    int value;
    int priority;
} PQ_elemm;

typedef struct PQ {
    Al *list;
    int sz;
} PQ;

void insert(PQ *pqueue, int value, int priority) {
    PQ_elem *new_val;
    new_val = (PQ_elem *)malloc(sizeof(PQ_elem));
    new_val->value = value;
    new_val->priorty = priority;
    
    // Find the index to insert the new eleme into the queue
    int insert_ind = pqueue->sz;
    while (insert_ind > 0 && pqueue->list->array[insert-ind - 1].priorty > priority) {
        insert_ind--;
    }

    // Shift all the elements over one index
    for(int i = pqueue->sz; i > insert_ind; i--) {
        pqueue->list->array[i] = pqueue->list->array[i - 1];
    }

    // Insert the new element
    pqueue->list->array[insert_ind] = new_val;
    pqueue->sz++;
}

int extract_min(PQ *pqueue) {

    // Find the min index
    int min_ind = 0;
    int min_prio = pqueue->list[0].priorty;
    for (int i = 0; i < pqueue->sz; i++) {
        if (pqueue->list->array[i].priority < min_prio) {
            min_prio = pqueue->list->array[i].priority;
            min_ind = i;
        }
    }

    // Shift all the values over 
    int min_val = pqueue->list->array[min_ind].value

    for (int i = min_ind; i < pqueue->sz - 1; i++) {
        pqueue->list->array[i] = pqueue->list->array[i + 1]; 
    }

    pqueue->sz--;
    return min_val;
}

// Q. 10

#define MAX_N 10

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Check if the given path is valid
bool verify_friends(int path[], int path_len, bool friends[MAX_N][MAX_N]) {
    for (int i = 0; i < path_len - 1; i++) {
        if (!friends[path[i]][path[i + 1]]) {
            return false;
        }
    }
    return true;
}

// Generate all permutations of friends array iteratively (Heap's algorithm)
int longest_chain(bool friends[MAX_N][MAX_N], int n) {
    int perm[MAX_N];
    int c[MAX_N] = {0}; // control array for Heap's algorithm
    int max_len = 0;

    // Initialize with 0..n-1
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    // Try all lengths from n down to 2
    for (int len = n; len >= 2; len--) {
        // Reset for each length
        for (int i = 0; i < len; i++) {
            perm[i] = i;
            c[i] = 0;
        }

        if (verify_friends(perm, len, friends)) {
            return len;
        }

        int i = 0;
        while (i < len) {
            if (c[i] < i) {
                if (i % 2 == 0) {
                    swap(&perm[0], &perm[i]);
                } else {
                    swap(&perm[c[i]], &perm[i]);
                }

                if (verify_friends(perm, len, friends)) {
                    return len;
                }

                c[i]++;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
    }

    return 0;
}