class Queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, value):
        self.queue.append(value)

    def dequeue(self):
        if not self.queue:
            print("ERROR: Empty queue")
            return None
        
        res = self.queue[0]
        self.queue = self.queue[1:]
        return res

    def is_empty(self):
        return not self.queue
