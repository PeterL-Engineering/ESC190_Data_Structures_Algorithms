# Painting Houses Continued

# Problem: Painting Houses
# Goal: Paint a row of n houses red, green, or blue st.
    # - Total cost is minimized cost(i, col) is the cost
    #   to paint the i-th hous in colour col
    # - No two adjacent houses have the same colour

# Subproblems: R(i), G(i), B(i) min cost to paint the first i houses
# with the i-th house painted col R/G/B
    # R(i) = cost(i, red) + min(G(i - 1), B(i - 1))
    # G(i) = cost(i, green) + min(R(i - 1), B(i - 1))
    # B(i) = cost(i, blue) + min(R(i - 1), G(i - 1))

    # Cost(i) = min(R(i), G(i), B(i))

################################################################################

N = 6

houses = [[7, 6, 7, 8, 9, 20],
          [3, 8, 9, 22, 12, 8],
          [16, 10, 4, 2, 5, 7]]


cost = [[0] * N,
        [0] * N,
        [0] * N] #R, G, B

# cost = [[0, 0, 0, 0, 0, 0]
#         [0, 0, 0, 0, 0, 0]
#         [0, 0, 0, 0, 0, 0]]



cost[0][0] = houses[0][0] # R[0]
cost[1][0] = houses[1][0] # G[0]
cost[2][0] = houses[2][0] # B[0]

for i in range(1, N):
    # the min cost to paint the first i houses, with the i-th being painted red
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted green
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted blue
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])

min(cost[0][5], cost[1][5], cost[2][5])

# We already know what colour to paint the last house

cols = [0] * N
i = N-1
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= min(cost[0][N-1], cost[2][N-1]):
    cols[N-1] = 1
else:
    cols[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = 10000
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:
            continue # If the next house is the same colour, skip
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col

# Solution dictionary

sol = {}
for i in range(N):
    sol[i] = ()
    for col in [0, 1, 2]:
        sol[i][col] = -1



def paint_house_cost_solution(houses, col, i):
    '''Return the cost of painting houses
    0, 1, 2, ... i, with the i-th houses painted col
    and the total cost minimized as well as the solution
    that corresponds to the minimum cost'''
    if i == 0:
        return houses[col][i], [col]

    cur_min = sum(sum(costs) for costs in houses)
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue
        cost_color_i = paint_house_cost_solution(houses, color, i-1)
                    # Cost of painting houses 0, 1, ...
                    # with the i-1th house painted with color color

        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
            cur_min_soln = cur_soln

            # Cur_min: the smaller of the total costs
            # up to i-1 with the two columns that are allowed
            # Cur_min_col: The color that gives the smaller
            # total cost
    sol[i][col] = cur_min_col
    return houses[col][i] + cur_min, cur_min_soln + [col]

######################################

# Greedy Algorithms

    # Given a denomination (d1, d2, d3, ...)
    # Find the smallest number of coins that can be used to make x

# Greedy Algorithm
    # 1. Sort the denomination in descending order
    # 2. Take as many of the largest denomnation coins possible
    # 3. Take as many of the second largest ...

# mincost(t): the least number of coins needed to make up amount t
 
# mincost(t) = 1 + mincost(t -d1), mincost(t - d2), ...

# mincost(0) = 0
# mincost(1) = 1
# mincost(2) = 3
# mincost(4) = 1
# mincost(5) = 1
# mincost(6) = 2
#              1 + min(mincost(5), mincost(2), mincost(1))
# mincost(7) = 3
#              1 + min(mincost(6), mincost(3), mincost(2))

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

print(mincost(8, [1, 4, 5, 10]))


############################################

# Intro to Q. 4 for Lab 8

# ["cats", "dog", "sand", "and", "cat"]
# Can you segment "catsandog"?

# can_seg["catsandog"] -> can_seg["andog"]
#                      -> can_seg["sandog"]

#############################################

# Introduction to Graph Theory

# A graph consists of a collection of nodes (vertices) and edges
    # Example application could be cities and direct flights that connect
    # A graph can also be called a directed graph if the connections have directions
    
