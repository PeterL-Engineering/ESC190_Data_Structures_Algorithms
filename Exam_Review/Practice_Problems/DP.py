# Lab 8 Questions -----------------------------------

# Q. 2

def min_coins(val, denominations):
    dp = [float('inf')] * (val + 1)
    dp[0] = 0  # Base case: 0 coins needed to make 0

    for i in range(1, val + 1):
        for coin in denominations:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[val] if dp[val] != float('inf') else -1  # -1 if not possible

# Q. 3

def min_coin_list(val, denominations):
    dp = [float('inf')] * (val + 1)
    dp[0] = 0  # Base case: 0 coins needed to make 0

    for i in range(1, val + 1):
        for coin in denominations:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp

# Q. 4

def coins_req(val, denominations):
    res = []
    while val > 0:
        for d in denominations:
            if val - d >= 0 and min_coins(val - d, denominations) == min_coins(val, denominations) - 1:
                res.append(d)
                val -= d
                break  # Move to the next value after choosing a coin
    return res

# Q. 5

def canBeSegmented(s, WordDict):
    if s == "":
        return True
    for word in WordDict:
        if s.startswith(word):
            if canBeSegmented(s[len(word):]):
                return True
    return False
