import numpy as np

# Simple Neural Network Computation


# implement the nn from slide 16 of n lecture
# assume that w is given as an np array and b is also given

def sigma(x):
    return 1/(1+np.exp(-x))

x = np.random.rand(4096)

# W is of size 1 x 4096 x 6
W = np.random.array(1, 4096, 6)

# b is of size 1 x 6
b = np.random.array(1, 6)

# z_1 = sigma(SUM W(1, j, 1) * x(j) + b(1, 1))

z = np.zeros((1, 6))

for k in range(6):
    # for j in range(4096):
    #     z[0, k] == W[0, j, k] * x[j]
    z[0, k] = np.dot(W[0, :, k], x)
    z[0, k] += b[0, k]

z = sigma(z)

# Extract Template for person at index 2

templ = []
for j in range(4096):
    templ.append(W[0, j, 2])
# templ is the thing we compute the dot product of x with

# Example questions 
#   Given a neural network, calculate the z
#   Perhaps might have to read a file with the values for W and b


# Neural Network Graph

class Node:
    def __init__(self, name, value=None):
        self.name = name
        self.value = value
        self. edges = []

    def add_edge(self, node, weight):
        self.edges.append({"node": node, "weight": weight})

    def __repr__(self):
        return f"Node({self.name}, {self.value})"   

import random
def create_nn_graph(input_dim, output_dim):
    for i in range(input_dim):
        node = Node(f"x{i}")
    for k in range(output_dim):
        node = Node(f"z{k}")
        z.append(node)
    for i in range(input_dim):
        for k in range(output_dim):
            w = random.random()
            x[i].add_edge(z[k], w)
            z[k].add_edge(x[i], w)

# "Need to know" slide 32

# Basically just compute all the outputs of the hidden layer
# And find the input that gives the highest output for the particular node
# ie input a picture of dogs would make the neuron corresponding to dogs go high

# To compute the hidden layer

x = np.random.rand(4096)

n_hid = 10
# W is of size 1 x 4096 x 6
W0 = np.random.array(1, 4096, n_hid)
W1 = np.random.array(1, n_hid, 6)


# b is of size 1 x 6
b0 = np.random.array(1, n_hid)
b1 = np.random.array(1, 6)
def nn(x, W0, W1, b0, b1, n_hid):
    hid = np.zeros((1, n_hid))
    z = np.zeros((1, 6))
    for k in range(n_hid):
        hid[0, k] = np.dot(W0[0, :, k], x)
        hid[0, k] += b0[0, k]

    for k in range(6):
        # for j in range(4096):
        #     z[0, k] == W[0, j, k] * x[j]
        z[0, k] = np.dot(W1[0, :, k], x)
        z[0, k] += b[0, k]

    return z, hid

# for hidden neuron 7, find the xs that activate it the most
neuron_7_acts = []

for i in range(10000):
    z, hid = nn(x[i], W0, W1, b0, b1, n_hid)
    neuron_7_acts.append((hid[0, 7], i))

neuron_7_acts.sort(reverse = True)
# the top 10 activations are for x's at indices [0][1], [1][1] ...
for i in range(10):
    print(f"x[{neuron_7_acts[i][1]}])")

# For graphs he could ask to use adjacency lists, matrices