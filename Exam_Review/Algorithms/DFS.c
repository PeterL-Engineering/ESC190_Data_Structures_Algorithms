#include "Stack.h"
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool DFS(Graph *graph, Node *start) {
    // Reset all nodes
    for (int i = 0; i < graph->node_count; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].distance_from_start = INFINITY;
    }

    // Stack initialization
    Stack *stack;
    init(&stack);
    push(stack, start);
    start->visited = 1;
    start->distance_from_start = 0;

    while (!isEmpty(stack)) {
        Node *cur = pop(stack);
        printf("Visited: %s\n", cur->name);

        for (int i = 0; i < cur->connection_count; i++) {
            Node *neighbor = cur->connections[i].node;
            if (!neighbor->visited) {
                neighbor->visited = 1;
                neighbor->distance_from_start = cur->distance_from_start + 1;
                push(stack, neighbor);
            }
        }
    }

    free_stack(stack); // if implemented

    return true;
}

bool DFS_recursive();