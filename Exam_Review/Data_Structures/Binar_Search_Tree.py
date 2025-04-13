class BST:
    def __init__(self, value):
        self.key = value
        self.left = None
        self.right = None

    def insert(self, value):
        if value < self.key:
            if self.left is None:
                self.left = BST(value)
            else:
                self.left.insert(value)
        else:
            if self.right is None:
                self.right = BST(value)
            else:
                self.right.insert(value)

    def get_val(self, value):
        if value == self.key:
            return True
        elif value < self.key:
            return self.left.get_val(value) if self.left else False
        else:
            return self.right.get_val(value) if self.right else False

    def find_min(self):
        current = self
        while current.left:
            current = current.left
        return current

    def remove_val(self, value):
        if value < self.key:
            if self.left:
                self.left = self.left.remove_val(value)
        elif value > self.key:
            if self.right:
                self.right = self.right.remove_val(value)
        else:
            if self.left is None:
                return self.right
            elif self.right is None:
                return self.left
            else:
                min_larger_node = self.right.find_min()
                self.key = min_larger_node.key
                self.right = self.right.remove_val(min_larger_node.key)
        return self

    def inorder(self):
        if self.left:
            self.left.inorder()
        print(self.key, end=' ')
        if self.right:
            self.right.inorder()
