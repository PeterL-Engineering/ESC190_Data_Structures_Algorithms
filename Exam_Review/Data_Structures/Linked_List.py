class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class LL:
    def __init__(self):
        self.head = None

    def append(self, val):
        new = Node(val)
        if not self.head:
            self.head = new
            return
        
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = new

    def insert(self, val, ind):
        new = Node(val)

        # Insert at head
        if ind == 0:
            new.next = self.head
            self.head = new
            return

        cur = self.head
        for i in range(ind - 1):
            if not cur or not cur.next and i < ind - 2:
                raise IndexError("Index out of range")
            cur = cur.next

        new.next = cur.next
        cur.next = new
