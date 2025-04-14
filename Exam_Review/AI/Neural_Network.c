#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define INPUT_SIZE 4096
#define HIDDEN_SIZE 10
#define OUTPUT_SIZE 6
#define NUM_INPUTS 10000

// --------------------- Activation ---------------------
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// --------------------- Neural Network ---------------------
void nn(double x[INPUT_SIZE], double W0[INPUT_SIZE][HIDDEN_SIZE], double W1[HIDDEN_SIZE][OUTPUT_SIZE],
        double b0[HIDDEN_SIZE], double b1[OUTPUT_SIZE],
        double hid[HIDDEN_SIZE], double out[OUTPUT_SIZE]) {

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        hid[i] = b0[i];
        for (int j = 0; j < INPUT_SIZE; ++j)
            hid[i] += W0[j][i] * x[j];
        hid[i] = sigmoid(hid[i]);
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        out[i] = b1[i];
        for (int j = 0; j < HIDDEN_SIZE; ++j)
            out[i] += W1[j][i] * hid[j];
        out[i] = sigmoid(out[i]);
    }
}

// --------------------- Graph Structures ---------------------
typedef struct Edge {
    int target;
    double weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    char name[16];
    double value;
    Edge* edges;
} Node;

// Add edge from `from` to `to` with weight
void add_edge(Node* nodes, int from, int to, double weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->target = to;
    edge->weight = weight;
    edge->next = nodes[from].edges;
    nodes[from].edges = edge;
}

// --------------------- Main ---------------------
int main() {
    srand(time(NULL));

    // Neural network weights and biases
    double W0[INPUT_SIZE][HIDDEN_SIZE];
    double W1[HIDDEN_SIZE][OUTPUT_SIZE];
    double b0[HIDDEN_SIZE];
    double b1[OUTPUT_SIZE];

    // Random initialization
    for (int i = 0; i < INPUT_SIZE; ++i)
        for (int j = 0; j < HIDDEN_SIZE; ++j)
            W0[i][j] = (double)rand() / RAND_MAX;

    for (int i = 0; i < HIDDEN_SIZE; ++i)
        for (int j = 0; j < OUTPUT_SIZE; ++j)
            W1[i][j] = (double)rand() / RAND_MAX;

    for (int i = 0; i < HIDDEN_SIZE; ++i)
        b0[i] = (double)rand() / RAND_MAX;
    
    for (int i = 0; i < OUTPUT_SIZE; ++i)
        b1[i] = (double)rand() / RAND_MAX;

    // Build graph for visualization
    Node input_nodes[INPUT_SIZE];
    Node hidden_nodes[HIDDEN_SIZE];
    Node output_nodes[OUTPUT_SIZE];

    for (int i = 0; i < INPUT_SIZE; ++i) {
        sprintf(input_nodes[i].name, "x%d", i);
        input_nodes[i].value = 0;
        input_nodes[i].edges = NULL;
    }

    for (int i = 0; i < HIDDEN_SIZE; ++i) {
        sprintf(hidden_nodes[i].name, "h%d", i);
        hidden_nodes[i].value = 0;
        hidden_nodes[i].edges = NULL;
    }

    for (int i = 0; i < OUTPUT_SIZE; ++i) {
        sprintf(output_nodes[i].name, "z%d", i);
        output_nodes[i].value = 0;
        output_nodes[i].edges = NULL;
    }

    // Connect graph (input -> hidden)
    for (int i = 0; i < INPUT_SIZE; ++i)
        for (int j = 0; j < HIDDEN_SIZE; ++j)
            add_edge(input_nodes, i, j, W0[i][j]);

    // Connect graph (hidden -> output)
    for (int i = 0; i < HIDDEN_SIZE; ++i)
        for (int j = 0; j < OUTPUT_SIZE; ++j)
            add_edge(hidden_nodes, i, j, W1[i][j]);

    // Input set
    double X[NUM_INPUTS][INPUT_SIZE];
    for (int i = 0; i < NUM_INPUTS; ++i)
        for (int j = 0; j < INPUT_SIZE; ++j)
            X[i][j] = (double)rand() / RAND_MAX;

    // Track top 10 activations for hidden neuron 7
    double top_acts[10] = {0};
    int top_inds[10] = {0};

    for (int i = 0; i < NUM_INPUTS; ++i) {
        double hid[HIDDEN_SIZE], out[OUTPUT_SIZE];
        nn(X[i], W0, W1, b0, b1, hid, out);
        double a = hid[7];
        for (int j = 0; j < 10; ++j) {
            if (a > top_acts[j]) {
                for (int k = 9; k > j; --k) {
                    top_acts[k] = top_acts[k-1];
                    top_inds[k] = top_inds[k-1];
                }
                top_acts[j] = a;
                top_inds[j] = i;
                break;
            }
        }
    }

    printf("Top 10 inputs that activate hidden neuron 7:\n");
    for (int i = 0; i < 10; ++i)
        printf("x[%d] -> activation: %f\n", top_inds[i], top_acts[i]);

    return 0;
}
