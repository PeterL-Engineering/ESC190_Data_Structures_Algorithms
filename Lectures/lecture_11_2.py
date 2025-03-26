# Making a Dijkstra's Algorithm

# From Graphs Slideshow
# Visited notes: S = (A, C)
# d(A) = 0
# d(C) = 1
# d(B) = 2
# d(E) = 3
# d(D) = 6
# d(G) = 8
# d(F) = 10
# d(H) = 14

######################################
# Queue: [(0, A)]
# d(A) = 0
# Queue: [(1, C), (2, B), (6, D)]
# d(C) = 1
# d(B) = 2
# Queue: [(8, G), (10, F)]
# d(G) = 8
# d(F) = 10




import numpy as np
import heapq as hq

pq = heapq.heapify([])
heapq.heappush(pq, (1, "Praxis"))
heapq.heappush(pq, (2, "Calculus"))

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

yyz = Node("YYZ")
lax = Node("LAX")
yul = Node("YUL")
yyz.connections.append(Con(lax, 1000))
yyz.connections.append(Con(yul, 300))

def dijkstra(start, end):
    start.distane_from_start = 0
    visited = set([start])
    current = start
    to_be_considered = [(0, start)]
    while current != end:

        cur_dist, current = heapq.heappop(to_be_considered)
        current.distance_from_start = cur_dist
        visited.add(current)
        for con in current.connections:
            if con.node in visited:
                continue
            heapq.heappush(to_be_considered, (con.weight + current.distance_from_start, con.node))
    return current.distance_from_start