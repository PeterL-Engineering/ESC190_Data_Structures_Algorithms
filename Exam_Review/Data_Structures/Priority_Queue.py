class PQ_elem:
    def __init__(self, data, priority):
        self.data = data
        self.priority = priority

class PQ:
    def __init__(self):
        self.pq = []

    def insert(self, data, priority):
        val = PQ_elem(data, priority)

        # Find the correct index to insert
        insert_ind = len(self.pq)  # Default to end
        for i in range(len(self.pq)):
            if self.pq[i].priority > priority:
                insert_ind = i
                break

        # Insert at the correct index
        self.pq.insert(insert_ind, val)

    def get_min_val(self):
        if not self.pq:
            print("ERROR: Empty priority queue")
            return None

        res = self.pq[0].data
        self.pq = self.pq[1:]  # Remove first element
        return res
