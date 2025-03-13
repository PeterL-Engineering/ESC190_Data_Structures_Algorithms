'''
Introduction to Graph Theory Continued

Representing a Graphs as Adjcency Matrices
    - If two nodes share an edge, we can put a '1' in the matrix entry
    - Otherwise we can put a '0' for all other entries

    - If we include the weights of the edges, we can put values other than 0
    - Thus we can instead put infinity for unconnected nodes
'''

# Idea: store a matrix inside of the graph object
#       access the matrix when querying edges
import numpy as np
class Graph:
    def __init__(self, num_nodes):
        self.adj_matrix = np.zeros((num_nodes, num_nodes))

    def is_edge(self, i, j):
        return self.adj_matrix[i][j] == 1
    
    def put_edge(self, i, j):
        self.adj_matrix[i][j] == 1
    
    def remove_edge(self, i, j):
        self.adj_matrix[i][j] == 0

    # setting up a matrix
    import numpy as np
    M = np.array((10, 10)) # a 10x10 matrix
    M_zeros = np.zeros((10, 10)) # a 10x10 matrix
    M[0][1] # Accessing row 0 column 1

if __name__ ==  '__main__':
    g = Graph(4) # Graph __init__ (g, 4)
    g.put_edge(1, 2) # Graph.put_edge(g, 1, 2)
    print(g.is_edge(1, 2)) # Return true

##############################

# Example of Classes in Python

class Student:
    def __init__(self, major, gpa):
        self.major = major
        self.gpa = gpa
    def print_student(self):
        print("Major: (self.major), GPA: (self.gpa)")
        if self.gpa > 3.6:
            print("DEAN'S LIST")

s = Student("Robo", 3.8)
s2 = Student("MI", 3.9)

# Further Example of Data Structures

'''
Stacks: LIFO ie last in, first out
    - Push: Put an element into the stack
    - Pop: Get the last element that was put onto the stack, remove that

Push 5
Push 10
Push 2
Pop # returns 2
Pop # returns 10
Psuh 20
Pop # returns 20
'''

class Stack:
    def __init__(self):
        self.data = []

    def push(self, elem):
        self.data.append(elem)

    def pop(self):
        # return self.data.pop
        ret_val = self.data[-1]
        self.data.remove(len(self.data) - 1)
        return ret_val