# Time Complexity of Memoizatoin and Dynamic Programming

def fib(n):
    A = [0] * (n + 1)
    A[0] = 0
    A[1] = 1
    for i in range(2, n + 1):
        A[i] = A[i - 1] + A[i - 2]
    return A[n]

def A(i, memo = {0: 0, 1: 1}):
    if i in memo:
        return memo[i]
    # if i == 0:
    #     return 0
    # if i == 1:
    #     return 1
    
    return A(i - 1) + A(i - 2)