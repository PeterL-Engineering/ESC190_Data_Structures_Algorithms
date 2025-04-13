import heapq
import Graph

def Dijkstra(g, start):
    start_i = g.node_names(start)

    dist = ['inf'] * g.num_nodes
    dist[start_i] = 0

    visited = [False] * g.num_nodes
    heap = []

    heapq.heappush(heap, (0, start_i))

    while heap:

        cur_dist, node = heapq.heappop(heap)

        if visited[node]:
            continue

        visited[node] = True

        neighbour = g.nodes[node].head

        while neighbour:
            neighbour_node = neighbour.data
            neighbour_weight = neighbour.weight

            if not visited[neighbour]:
                new_dist = cur_dist + neighbour_weight
                if (new_dist < dist[neighbour_node]):
                    dist[neighbour_node] = new_dist

                heapq.heappush(heap, (new_dist, neighbour_node))
            neighbour = neighbour.next

    return dist