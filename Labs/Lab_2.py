# Question 4: Your task is to implement binary search deluxe right, 
# which returns the index of the last occurrence of target in L, in 
# O(log(n)) time. (Note: finding the first occurrence and then looking 
# through the list from there is not O(log(n)) time. One idea: what is 
# the condition that indicates that you found the right-most occurrence of target?)

def binary_search_delux_right(L, target):
    """Return the index of the last occurence of target in L.
       Assume that target is in L"""

    left = 0
    right = len(L) - 1
    res = -1
    
    while left <= right:
        mid = (left + right) // 2
        if L[mid == target]:
            res = mid
            left = mid + 1
        elif L[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return res
