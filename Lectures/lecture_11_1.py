# Worked on PQ.py ie Priority Queues

# Cheapest Paths in Graphs (Edges now have weights)
''' Dijkstra's Algorithm

Dijkstra(G = (V, E), source)
    S = (source) # S is the set of explored nodes
    d (source) = 0 # d(v) is the shortest path from source to v

    while S != v:
        choose v \in V\S st d(u) + |(u, v) | is minimized
        add v to S, set d(v) = d(u) + |(u, v) |
'''