# Want: The same kind of functions as we have in Graph (see lecture_9_2.py)
# Want: To represent the data using adjcency list

# For each node, keep a list of its neighbours (ie. nodes connected)
# Use linked lists in order to store the neighbours

# One possible design uses a Python list of linked list

# We first need to define the linked list in Python

import LL

class Graph2:
    def __init__(self, num_nodes):
        self.nodes = []
        for i in range(self.num_nodes):
            self.nodes.append(LL.LL())
    def is_edge(self, i, j):
        return self.nodes[i].is_in(j)

    def put_edge(self, i, j):
        if self.is_edge(i, j):
            return
        self.nodes[i].insert(0, j)

    def remove_edge(self, i, j):
        self.nodes[i].remove(j)

        # If the user is allowed to call put_edge(1, 2) twice need to 
        # either take care of it inside put_edge or inside remove_edge
