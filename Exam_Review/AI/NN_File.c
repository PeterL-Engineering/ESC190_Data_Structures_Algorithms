/*
Let's suppose the weights and biases are stored in a txt file in the format below

Starting at the first line, you have all the bias values with a space in between, then
every line after is the weights for each output. In this case 6 lines of 4096 weights.

1 2 3 4 5 6
3 4 5 6 7 8 ...
1 5 6 8 9 0 ...
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void read_file(const char *filename, int input_dim, int output_dim, int ***weights, int **biases) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("ERROR: Could not open file");
        exit(1);
    }

    // Allocate memory
    *weights = (int **)malloc(sizeof(int *) * output_dim);
    *biases = (int *)malloc(sizeof(int) * output_dim);
    for (int i = 0; i < output_dim; i++) {
        (*weights)[i] = (int *)malloc(sizeof(int) * input_dim);
    }

    char line[65536];

    // --- Read biases ---
    if (fgets(line, sizeof(line), f) == NULL) {
        perror("ERROR: Failed to read biases line");
        exit(1);
    }

    int idx = 0, val = 0, sign = 1;
    for (char *p = line; *p != '\0' && idx < output_dim; p++) {
        if (*p == '-') {
            sign = -1;
        } else if (isdigit(*p)) {
            val = val * 10 + (*p - '0');
        } else if (*p == ' ' || *p == '\n') {
            (*biases)[idx++] = val * sign;
            val = 0;
            sign = 1;
        }
    }

    // --- Read weights ---
    for (int i = 0; i < output_dim; i++) {
        if (fgets(line, sizeof(line), f) == NULL) {
            perror("ERROR: Not enough weight lines");
            exit(1);
        }

        idx = 0;
        val = 0;
        sign = 1;

        for (char *p = line; *p != '\0' && idx < input_dim; p++) {
            if (*p == '-') {
                sign = -1;
            } else if (isdigit(*p)) {
                val = val * 10 + (*p - '0');
            } else if (*p == ' ' || *p == '\n') {
                (*weights)[i][idx++] = val * sign;
                val = 0;
                sign = 1;
            }
        }
    }

    fclose(f);
}

void compute_outputs(int *inputs, int **weights, int *biases, int input_dim, int output_dim) {
    int *z = (int *)malloc(sizeof(int) * output_dim);

    for (int i = 0; i < output_dim; i++) {
        for (int k = 0; k < intput_dim; k++) {
            z[i] = weights[i][k] * x[k];
        }

        z[i] += biases[i];
    }
}

typedef struct Edge {
    char *neighbour;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Node {
    char *name;
    int val;
    Edge *edges; // linked list of edges
} Node;


void add_edge(Node *node, char *neighbour, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->neighbour = neighbour;
    new_edge->weight = weight;
    new_edge->next = node->edges;
    node->edges = new_edge;
}


void create_nn_graph(int input_dim, int output_dim, Node **inputs, Node **outputs, int *weights) {
    // Create input nodes
    for (int i = 0; i < input_dim; i++) {
        char label[16];
        sprintf(label, "x%d", i);
        inputs[i] = create_node(label, i);
    }

    // Create output nodes
    for (int i = 0; i < output_dim; i++) {
        char label[16];
        sprintf(label, "z%d", i);
        outputs[i] = create_node(label, i);
    }

    // Connect with weights: weights[k * input_dim + i]
    for (int i = 0; i < input_dim; i++) {
        for (int k = 0; k < output_dim; k++) {
            int w = weights[k * input_dim + i];

            add_edge(inputs[i], outputs[k]->name, w);
            add_edge(outputs[k], inputs[i]->name, w);
        }
    }
}
