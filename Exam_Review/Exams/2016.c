// Q. 3

#define NODES 6;

typedef struct adjMat {
    int mat[NODES][NODES];
    int visitedNodes[NODES];
} adjMat;

Queue *initQueue();
void enqueue(Queue *q, int node);
int dequeue(Queue *q);
int isEmpty(Queue *q);

void bfTraversal(adjMat *aM, int start) {
    for (int i = 0; i < NODES; i++) {
        aM->visitedNodes[i] = 0;
    }

    Queue *q = initQueue();
    enqueue(q, start);
    aM->visitedNodes[start] = 1;

    while (!isEmpty(q)) {
        int cur = dequeue(q);
        printf("Visited: %d\n", cur);

        for (int i = 0; i < NODES; i++) {
            if (aM->mat[cur][i] == 1 && aM->visitedNodes[i] == 0) {
                enqueue(q, i);
                aM->visitedNodes[i] = 1;
            }
        }
    }
}

// Q. 4

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *mergeLinkedLists(Node *L1, Node *L2) {
    if (!L1) return L2;
    if (!L2) return L1;

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = L1->data;
    head->next = NULL;

    Node *tail = head;
    Node *cur1 = L1->next;
    Node *cur2 = L2;
    int count = 0;

    while (cur1 && cur2) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;

        if (count % 2 == 0) {
            newNode->data = cur2->data;
            cur2 = cur2->next;
        } else {
            newNode->data = cur1->data;
            cur1 = cur1->next;
        }

        tail->next = newNode;
        tail = newNode;
        count++;
    }

    // Append the remaining nodes
    if (cur1) tail->next = cur1;
    else if (cur2) tail->next = cur2;

    return head;
}

// Q. 5

#define NODES 6
typedef struct Node {
    int data;
    struct Node *link;
} Node;

typedef struct adjList {
    Node *ptrArray[NODES];
    int visitedNodes[NODES];
} adjList;

int dfsLongestPath(adjList *aL, int node, int visited[], int memo[]) {
    if (memo[node] != -1) return memo[node];

    visited[node] = 1;
    int maxLength = 0;
    Node *cur = aL->ptrArray[node];

    while (cur) {
        if (!visited[cur->data]) {
            int length = 1 + dfsLongestPath(aL, cur->data, visited, memo);
            if (length > maxLength) maxLength = length;
        }
        cur = cur->link;
    }

    visited[node] = 0; // allow revisiting for other paths
    memo[node] = maxLength;
    return maxLength;
}

int longestPathLength(adjList *aL, int startNode) {
    int visited[NODES] = {0};
    int memo[NODES];
    for (int i = 0; i < NODES; i++) memo[i] = -1;

    return dfsLongestPath(aL, startNode, visited, memo);
}