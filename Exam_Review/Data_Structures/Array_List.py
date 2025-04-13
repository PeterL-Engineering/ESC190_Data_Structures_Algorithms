import ctypes

class ArrayList:
    def __init__(self):
        self.n = 0  # Number of elements
        self.capacity = 1  # Initial capacity
        self.array = self._make_array(self.capacity)

    def __len__(self):
        return self.n

    def __getitem__(self, index):
        if not 0 <= index < self.n:
            raise IndexError('Index out of bounds!')
        return self.array[index]

    def append(self, item):
        if self.n == self.capacity:
            self._resize(2 * self.capacity)
        self.array[self.n] = item
        self.n += 1

    def _resize(self, new_capacity):
        new_array = self._make_array(new_capacity)
        for i in range(self.n):
            new_array[i] = self.array[i]
        self.array = new_array
        self.capacity = new_capacity

    def _make_array(self, capacity):
        return (capacity * ctypes.py_object)()

    def __str__(self):
        return "[" + ", ".join(str(self.array[i]) for i in range(self.n)) + "]"
