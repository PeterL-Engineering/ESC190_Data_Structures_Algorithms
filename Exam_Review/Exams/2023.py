# Q. 6 Already did it in C but practice in Python

# Q. 7

class MyList:
    def __init__(self, nums):
        self.nums = nums

    def average(self):
        return sum(self.nums) / len(self.nums)

    def __lt__(self, other):
        return self.average() < other.average()

    def __repr__(self):
        return repr(self.nums)

def sort_lists(my_lists):
    return sorted(my_lists)

# Q. 9

def min_cost_plan(cost):
    n = len(cost)
    min_cost = [0] * n
    plan = [0] * n

    # Base cases
    min_cost[-1] = cost[-1]
    if n >= 2:
        min_cost[-2] = cost[-2]
    if n >= 3:
        min_cost[-3] = cost[-3]

    for i in range(n - 4, -1, -1):
        choices = [
            (min_cost[i + 1], 1),
            (min_cost[i + 2], 2),
            (min_cost[i + 3], 3)
        ]
        best_cost, step = min(choices)
        min_cost[i] = cost[i] + best_cost
        plan[i] = step

    # Build the path
    i = 0
    min_plan = []
    while i < n - 1:
        step = plan[i]
        if step == 0:  # No more steps recorded
            break
        min_plan.append(step)
        i += step

    return min_plan

            