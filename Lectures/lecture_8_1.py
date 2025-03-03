# A Python class is essentially like a struct in C
# There are fields (there and also methods and operators)

class student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade

    def __lt__(self, other):
        return self.grade < other.grade
        # retun self.name < other.name
        # could use this to sort the list of students
    
# bob = student("Bob", 52)
# charlie = student("Charlie", 50)
# student.__lt__(bob, charlie) = false

#another way to call __lt__
# bob < charlie # would call student.__t__ automatically

class Queue:
    def __init__(self):
        self.array = []

    def enqueue(self, item):
        self.array.append(item)
    
    def dequeue(self, item):
        #return sel.array.pop(0)
        ret = self.array[0]
        del self.array[0]
        return ret

if __name__ == "__main__":
    q = Queue()
    # Queue.enqueue(q, 5)
    q.enqueue(5) # same as  Queue.enqueue(q, 5) 

    s = student("Bob", 52)
    print(s.name, s.grade)

# Equivalent struct in C
# struct student {
#     char *name;
#     int age; 
# }