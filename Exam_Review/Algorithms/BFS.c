#include "Queue.h"
#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

bool BFS(Graph *graph, Node *start) {
    // Reset all nodes
    for (int i = 0; i < graph->node_count; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].distance_from_start = INFINITY;
    }

    // Stack initialization
    Queue *queue;
    init(&queue);
    enqueue(queue, start);
    start->visited = 1;
    start->distance_from_start = 0;

    while (!is_empty(queue)) {
        Node *cur = dequeue(queue);
        printf("Visited: %s\n", cur->name);

        for (int i = 0; i < cur->connection_count; i++) {
            Node *neighbor = cur->connections[i].node;
            if (!neighbor->visited) {
                neighbor->visited = 1;
                neighbor->distance_from_start = cur->distance_from_start + 1;
                enqueue(queue, neighbor);
            }
        }
    }

    free_queue(queue); // if implemented

    return true;
}