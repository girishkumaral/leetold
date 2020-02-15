def how_many_BSTs(n):
    T=0
    if (n == 0):
        return 1
    if (n == 1):
        return 1
    else:
        for j in range(0, n):
            T += how_many_BSTs(j) * how_many_BSTs(n-1-j)
    return T
