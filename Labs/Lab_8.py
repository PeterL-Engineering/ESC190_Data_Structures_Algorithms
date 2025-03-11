# Question 2 a)

# OPT(n) = min(OPT(n-1), OPT(n-4), OPT(n-5)) + 1

# Question 2 b)

def list_cost(t, denominations):
    costs = []
    for i in range(t+ 1):
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

# Question 2 part c)

def coins_for_target(t, denominations):
    coins_list = []

    while t > 0:
        for d in denominations:
            # Check if the number of coins required using denomination d 
            # matches the mincost for target t
            if t - d >= 0 and mincost(t - d, denominations) + 1 == mincost(t, denominations):
                coins_list.append(d)
                t -= d
                break  # Move to the next iteration after selecting a coin

    return coins_list

print(coins_for_target(11, [1, 4, 5]))

# Question 3

def canBeSegmented(s, wordDict):
    if s == "":
        return True  # Base case: empty string is always segmentable
    
    for word in wordDict:
        wordlen = len(word)
        if s[:wordlen] == word:
            if canBeSegmented(s[wordlen:], wordDict):  # Recursive call with return check
                return True  # If any segmentation works, return True immediately
    
    return False  # If no word fits, return False

print(canBeSegmented("sandysand", ["sand", "sandy"]))