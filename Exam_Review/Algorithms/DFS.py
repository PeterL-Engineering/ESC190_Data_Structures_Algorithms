from Stack import Stack
from Graph import Graph

def DFS(g, start):
    start_i = g.node_names(start)
    visited = [False] * g.num_nodes
    S = Stack()
    S.push(start_i)

    while not S.is_empty():
        node_index = S.pop()

        if not visited[node_index]:
            visited[node_index] = True

            neighbor = g.nodes[node_index].head
            while neighbor:
                if not visited[neighbor.data]:
                    S.push(neighbor.data)
                neighbor = neighbor.next
