from Queue import Queue
from Graph import Graph

def BFS(g, start):
    start_i = g.node_names(start)
    visited = [False] * g.num_nodes
    Q = Queue()
    Q.enqueue(start_i)

    while not Q.is_empty():
        node_index = Q.dequeue()
        
        if not visited[node_index]:
            visited[node_index] = True

            neighbor = g.nodes[node_index].head
            while neighbor:
                if not visited[neighbor.data]:
                    Q.enqueue(neighbor.data)
                neighbor = neighbor.next
