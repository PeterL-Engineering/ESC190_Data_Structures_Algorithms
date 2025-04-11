// Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_NAME_LEN 100

// Forward declaration
typedef struct Node Node;

typedef struct Con {
    Node* node;
    float weight;
} Con;

struct Node {
    int id;
    char name[MAX_NAME_LEN];
    float value;
    Con* connections;
    int connection_count;
    float distance_from_start;
    int visited;
};

typedef struct {
    Node *nodes;
    int node_count;
} Graph;

// Function declarations
void add_node(Graph* graph, char* name);
Node* find_node(Graph* graph, const char* name);
void is_edge_name(Graph graph, char* node1, char* node2);
bool is_edge(Graph graph, char* node1, char* node2);
void put_edge_name(Graph* graph, char* node1, char* node2);
void put_edge(Graph* graph, char* node1, char* node2);
void remove_edge(Graph* graph, char* node1, char* node2);

#endif // GRAPH_H
