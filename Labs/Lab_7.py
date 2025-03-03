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

    def enqueue(self, item):

        if self.end == len(self) - 1:
            self.end = 0
        else:
            self.end += 1

        self.array[self.end] = item
    
    def dequeue(self):
        #return sel.array.pop(0)
        ret = self.array[0]
        del self.array[0]

        if self.begin == len(self.array) - 1:
            self.begin = 0
        else:
            self.begin += 1

        return ret
    
if __name__ == "__main__":
    q = Queue(6)
    q.enqueue(5)
    q.enqueue(4)
    q.enqueue(3)
    print(str(q))