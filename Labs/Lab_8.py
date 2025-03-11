# Question 2 a)

# OPT(n) = min(OPT(n-1), OPT(n-4), OPT(n-5)) + 1

# Question 2 b)

def list_cost(t, denominations):
    costs = []
    for i in range(i <= t):
        costs.append(mincost(i, denominations))

    return costs

def mincost(t, denominations):
    if t < 0:
        return float('inf')
    if t == 0:
        return 0
    if t in denominations:
        return 1
    cur_min = float('inf')
    for d in denominations:
        cur_min = min(cur_min, 1 + mincost(t-d, denominations))
    return cur_min

print(list_cost(5, [1, 4, 5]))