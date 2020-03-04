#
# Complete the max_product_from_cut_pieces function below.
#

def helper(n, cache):
    #print(n, cache)

    if n == 1:
        return 1

    if n == 2:
        return 2
        
    if n == 3:
        return 3
    
    if cache[n] != -1:
        return cache[n]
    
    max = -1
    for i in range(2, n):
        #print("Calling {0} for n {1} {2}".format(n-i, n, i))
        p = (n-i)  * (helper(i, cache))
        #print("returned {0}".format(p))
        if max < p:
            max = p

    cache[n] = max
    #print("max cuts for {0} is {1}".format(n, max))
    return cache[n]

def max_product_from_cut_pieces(n):
    cache = [-1 for _ in range(n+1)]
    if n == 2:
        return 1
    if n == 3:
        return 2
    return helper(n, cache)
