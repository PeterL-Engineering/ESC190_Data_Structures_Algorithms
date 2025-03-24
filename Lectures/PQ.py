class PQ:
    def __init__(self):
        self.queue = []

    def insert(self, data, priority):
        self.queue.append((data, priority))

    def extract_min(self):
        min_index = 0

        # Find the data with the lowest priority
        for i in range(len(self.queue)): # O(n) is very slow
            if self.queue[i][1] < self.queue[min_index][1]:
                min_index = i
        return self.queue.pop[min_index][0]
    
pq = PQ()
pq.insert("Mike", 3)
pq.insert("Bob", 2)
pq.insert("Alice", 1)
pq.insert("Eve", 5)

print(pq.extract_min()) # Should return Ailce
print(pq.extract_min()) # Should return Bob
