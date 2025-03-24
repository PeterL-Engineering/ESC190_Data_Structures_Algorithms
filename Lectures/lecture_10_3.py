# Want: The same kind of functions as we have in Graph (see lecture_9_2.py)
# Want: To represent the data using adjcency list

# For each node, keep a list of its neighbours (ie. nodes connected)
# Use linked lists in order to store the neighbours

# One possible design uses a Python list of linked list

# We first need to define the linked list in Python

import LL

class Graph2:
    def __init__(self, num_nodes = 0):
        self.nodes = []
        self.node_names = {}
        self.node_names_rev = {} 
        self.num_nodes = num_nodes  
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL())

    def add_node(self, name):
        self.node_names[name] = len(self.nodes)
        self.node_names_rev[len(self.nodes)] = name
        self.nodes.append(LL.LL())
        self.num_nodes += 1

    def is_edge_name(self, name1, name2):
        return self.is_edge(self.node_names[name1], self.node_names[name2])
    
    def is_edge(self, i, j):
        return self.nodes[i].is_in(j)
    
    def put_edge_name(self, name1, name2):
        return self.put_edge(self.node_names[name1], self.node_names[name2])
    
    def put_edge(self, i, j):
        if self.is_edge(i, j):
            return
        self.nodes[i].insert(0, j)

    def remove_edge(self, i, j):
        self.nodes[i].remove(j)

        # If the user is allowed to call put_edge(1, 2) twice need to 
        # either take care of it inside put_edge or inside remove_edge

import ds #ds.py has class queue and stack

#Note BFT requires Queue and Stack
def breadth_first_traversal(g, start_name):
    start_i = g.node_names(start_name)
    visited = [False] * g.num_nodes
    DS = ds.Queue()
    DS.add(start_i)
    
    # Keep getting a node for DS, adding all its neighbours
    # And hten visiting the node

    while not DS.is_empty():
        cur = DS.get()
        if not visited[cur]:
            print(g.node_names_rev[cur])
            visited[cur] = True

            # Now add all the neighbours 
            # (nodes with an edge from cur to DS)
            # to be visited later

            cur = g.nodes[cur].head
            while cur:
                if not visited(cur.data):
                    DS.add(cur.data)
                cur = cur.next

def depth_first_traversal(g, start_name):
    start_i = g.node_names(start_name)
    visited = [False] * g.num_nodes
    DS = ds.Stack()
    DS.add(start_i)
    
    # Keep getting a node for DS, adding all its neighbours
    # And hten visiting the node

    while not DS.is_empty():
        cur = DS.get()
        if not visited[cur]:
            print(g.node_names_rev[cur])
            visited[cur] = True

            # Now add all the neighbours 
            # (nodes with an edge from cur to DS)
            # to be visited later

            cur = g.nodes[cur].head
            while cur:
                if not visited(cur.data):
                    DS.add(cur.data)
                cur = cur.next

def DFS_recursive(g, cur, visited):
    if visited == None:
        visited = [False] * g.num_nodes
    cur_i = g.node_names[cur]
    cur_neighbour = g.nodes[cur_i].head
    visited[cur_i] = True
    print(cur)
    while cur_neighbour:
        if not visited[g.node_names[cur_neighbour.data]]:
            DFS_recursive(g, cur_neighbour.data, visited)
        cur_neighbour = cur_neighbour.next

# node_names["YYZ"] = 0
# node_names_rev[0] = "YYZ"            

if __name__ == '__main__':
    airports = Graph2()
    airports.add_node("YYZ")
    airports.add_node("YVR")
    airports.add_node("JFK")
    airports.add_node("YUL")
    airports.add_node("LAX")
    airports.add_node("SFO")
    airports.add_node("YXZ")

    # 0 YYZ Neighbours: YUL -> JFK -> YVR -> NULL
    # 1 YVR Neighbours: YVR -> NULL
    # 2 JFK Neighbours: LAX -> NULL
    # 3 YUL Neighbours: YXZ -> NULL
    # 4 LAX Neighbours: SFO -> NULL
    # 5 SFO Neighbours: NULL
    # 6 YXZ Neighbours: NULL

    airports.put_edge_name("YVR", "YYZ")
    airports.put_edge_name("YYZ", "YVR")
    airports.put_edge_name("YYZ", "JFK")
    airports.put_edge_name("YYZ", "YUL")
    airports.put_edge_name("JFK", "LAX")
    airports.put_edge_name("LAX", "SFO")
    airports.put_edge_name("YUL", "YXZ")

    depth_first_traversal(airports, "YVR")
        #     YYZ -> YUL -> YXZ
        #    / ^ \
        #   v /   v
        #  YVR    JFK -> LAX-> SFO