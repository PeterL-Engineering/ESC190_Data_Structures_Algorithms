class Queue:
    def __init__(self, size):
        self.array = [None] * size
        self.begin = 0
        self.end = size - 1
 
    def __str__(self):
        if self.begin == self.end:  # Empty queue case
            return ""

        result = []
        i = self.begin

        while True:

            if self.array[i] != ' ':
                result.append(str(self.array[i]))  # Append as a string

            if i == self.end:
                break  # Stop when reaching the end index

            i = (i + 1) % len(self.array)  # Wrap around if needed

        return ' '.join(result)  # Join elements with a space

    def __lt__(self, other):
        if self.is_empty() and not other.is_empty():
            return True  # Empty queue is considered "less than" a non-empty queue
        if not self.is_empty() and other.is_empty():
            return False  # Non-empty queue is "greater than" an empty queue

        i, j, k = self.begin, other.begin, 0  # Start from respective begin indices
        self_size = (self.end - self.begin + len(self.array)) % len(self.array) + 1
        other_size = (other.end - other.begin + len(other.array)) % len(other.array) + 1
        min_size = min(self_size, other_size)

        while k < min_size:
            if self.array[i] < other.array[j]:
                return True
            elif self.array[i] > other.array[j]:
                return False

            i = (i + 1) % len(self.array)  # Wrap around circularly
            j = (j + 1) % len(other.array)
            k += 1

        return self_size < other_size  # Compare lengths if equal so far

    def enqueue(self, item):

        if self.end == len(self.array) - 1:
            self.end = 0
        else:
            self.end += 1

        self.array[self.end] = item
    
    def dequeue(self):
        #return sel.array.pop(0)
        ret = self.array[self.begin]
        del self.array[self.begin]

        if self.begin == len(self.array) - 1:
            self.begin = 0
        else:
            self.begin += 1

        return ret
    
def sort_queues(ls_qs):
    ls_qs.sort()
    
if __name__ == "__main__":
    q = Queue(6)
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(3)
    print(str(q))