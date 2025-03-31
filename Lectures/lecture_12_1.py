# Binary Search Trees

class MySet:
    def __init__(self):
        self.data = []
    def insert(self, x):
        if x not in self.data:
            self.data.append(x)
    def is_in(self,x):
        return x in self.data

# Insertion: O(n)
# Search (is in) : O(n)

[("esc190", "A+"), ("esc195", "D-")]

class MyDict:
    def __init__(self):
        self.data = []
    def insert(self, x, value):
        if x not in self.data:
            self.data.append((x, value))
    def is_in(self, x):
        for k, val in self.data:
            if k == x:
                return True
        return False
    def get(self, x):
        for k, val in self.dat:
            if k == x:
                return val
            return None

# Insertion O(n)


'''                             5
                            /       \
                           3          7
                          /  \       /  \
                         2     4     6    8
                         
There are 1 + 2 + 4  = 2 * 3 - 1 = 7 nodes

In general for a tree of height h, there are 2^h - 1 nodes for a complete tree
So we can say that it is h ~ log(n)

h is the number of steps needed in the worst case to find a node in the tree
so search in binary tree that's complete is O(log(n))'''

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


def make_tree():
    root = Node((3, "Alice"))
    root.left = Node((2, "Bob"))
    root.right = Node((5, "Charlie"))
    root.left.left = Node((0, "Dave"))
    root.left.right = Node((2, "Eve"))
   #     3
   #    /  \
   #   1   5
   # / \
   # 0  2
    return root

def get_val(key, root):
    '''Get the name that corresponds to the key
    Assume that root is the root of a Binary Search Tree'''

    if root == None:
        return None
    if key == root.val[0]:
        return root.val[1]
    if key < root.val[0]:
        return get_val(key, root.left)
    else:
        return get_val(key, root.right)
    
# What we've seen: a way to implement dictionaries with O(logn) retrieval
# Assuming we can make a balanced binary search tree using the keys