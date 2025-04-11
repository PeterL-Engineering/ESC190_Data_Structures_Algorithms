#include "Priority_Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Forward declaration
struct Node;

typedef struct Con {
    struct Node* node;
    float weight;
} Con;

typedef struct Node {
    int id;  // Unique identifier for the node
    float value;
    Con* connections; // dynamically allocated array of connections
    int connection_count; // number of connections
    float distance_from_start;
    int visited;
} Node;

typedef struct {
    Node *nodes;
    int node_count;
} Graph;

float dijkstra(Graph *graph, Node **node_map, Node *start_node) {
    // Initialize the start node
    start_node->distance_from_start = 0;

    // Initialize all nodes
    for (int i = 0; i < graph->node_count; i++) {
        graph->nodes[i].distance_from_start = INFINITY;
        graph->nodes[i].visited = 0;
    }

    // Create a priority queue
    PQ *queue;
    create_prio_queue(&queue);

    // Insert the start node into the priority queue
    insert(queue, start_node->id, 0);

    while (!is_empty(queue)) {
        int cur_id = extract_min(queue);  // Get node with the minimum distance
        Node* cur = node_map[cur_id];

        if (cur->visited == 1) {
            continue;
        }

        cur->visited = 1;

        // Loop through neighbors (connections)
        for (int i = 0; i < cur->connection_count; i++) {
            Node *neighbour = cur->connections[i].node;
            float weight = cur->connections[i].weight;

            if (neighbour->visited == 1) {
                continue;
            }

            // Calculate new distance for neighbor
            float new_dist = cur->distance_from_start + weight;

            // If a shorter path is found, update the neighbor's distance and add it to the queue
            if (new_dist < neighbour->distance_from_start) {
                neighbour->distance_from_start = new_dist;
                insert(queue, neighbour->id, new_dist);
            }
        }
    }

    // Return the shortest distance to the goal node 
    return start_node->distance_from_start;  
}
