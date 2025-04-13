import Linked_List

class Graph:
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