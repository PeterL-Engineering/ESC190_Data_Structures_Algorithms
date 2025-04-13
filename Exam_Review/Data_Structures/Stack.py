class Stack:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)  # Push to end

    def pop(self):
        if not self.stack:
            raise IndexError("pop from empty stack")
        return self.stack.pop()  # Pop from end
