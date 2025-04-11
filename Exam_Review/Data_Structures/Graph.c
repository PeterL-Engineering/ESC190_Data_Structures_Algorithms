#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Graph.h"

#define MAX_NAME_LEN 100

// typedef struct Node Node;

// typedef struct Con {
//     Node* node;
//     float weight;
// } Con;

// struct Node {
//     int id;
//     char name[MAX_NAME_LEN];
//     float value;
//     Con* connections;
//     int connection_count;
//     float distance_from_start;
//     int visited;
// };

// typedef struct {
//     Node *nodes;
//     int node_count;
// } Graph;

Node* find_node(Graph* graph, const char* name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, name) == 0) {
            return &graph->nodes[i];
        }
    }
    return NULL;
}

void add_node(Graph* graph, char* name) {
    if (find_node(graph, name)) return; // Node already exists

    graph->nodes = realloc(graph->nodes, (graph->node_count + 1) * sizeof(Node));
    Node* new_node = &graph->nodes[graph->node_count];
    new_node->id = graph->node_count;
    strncpy(new_node->name, name, MAX_NAME_LEN);
    new_node->value = 0;
    new_node->connections = NULL;
    new_node->connection_count = 0;
    new_node->distance_from_start = -1;
    new_node->visited = 0;

    graph->node_count++;
}

void connect_nodes(Node* n1, Node* n2, float weight) {
    n1->connections = realloc(n1->connections, (n1->connection_count + 1) * sizeof(Con));
    n1->connections[n1->connection_count].node = n2;
    n1->connections[n1->connection_count].weight = weight;
    n1->connection_count++;
}

bool is_edge(Graph graph, char* node1, char* node2) {
    Node* n1 = find_node(&graph, node1);
    Node* n2 = find_node(&graph, node2);
    if (!n1 || !n2) return false;

    for (int i = 0; i < n1->connection_count; i++) {
        if (n1->connections[i].node == n2) return true;
    }
    return false;
}

void is_edge_name(Graph graph, char* node1, char* node2) {
    printf("%s\n", is_edge(graph, node1, node2) ? "Yes" : "No");
}

void put_edge(Graph* graph, char* node1, char* node2) {
    Node* n1 = find_node(graph, node1);
    Node* n2 = find_node(graph, node2);
    if (!n1 || !n2) return;

    if (!is_edge(*graph, node1, node2)) {
        connect_nodes(n1, n2, 1.0f);
        connect_nodes(n2, n1, 1.0f); // undirected
    }
}

void put_edge_name(Graph* graph, char* node1, char* node2) {
    put_edge(graph, node1, node2);
}

void remove_edge(Graph* graph, char* node1, char* node2) {
    Node* n1 = find_node(graph, node1);
    Node* n2 = find_node(graph, node2);
    if (!n1 || !n2) return;

    for (int i = 0; i < n1->connection_count; i++) {
        if (n1->connections[i].node == n2) {
            for (int j = i; j < n1->connection_count - 1; j++) {
                n1->connections[j] = n1->connections[j + 1];
            }
            n1->connection_count--;
            n1->connections = realloc(n1->connections, n1->connection_count * sizeof(Con));
            break;
        }
    }

    for (int i = 0; i < n2->connection_count; i++) {
        if (n2->connections[i].node == n1) {
            for (int j = i; j < n2->connection_count - 1; j++) {
                n2->connections[j] = n2->connections[j + 1];
            }
            n2->connection_count--;
            n2->connections = realloc(n2->connections, n2->connection_count * sizeof(Con));
            break;
        }
    }
}