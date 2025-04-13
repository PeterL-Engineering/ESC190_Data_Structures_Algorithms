# Q. 9

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self, root):
        self.root = Node(root)

Root = Node(1)
Root.left = 4
Root.right = 5
Root.right.left = 7

def BST_sum(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return 0
    return root.value + BST_sum(root.left) + BST_sum(root.right)
