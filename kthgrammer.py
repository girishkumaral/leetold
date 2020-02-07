import math

def grammer(N, K):
    #print(N ,K)
    if N == 1:
        return 0
    if N == 2:
        if K is 1:
            return 0
        if K is 2:
            return 1
    if N == 3:
        if K is 1:
            return 0
        if K is 2:
            return 1
        if K is 3:
            return 1
        if K is 4:
            return 0
    parent = grammer(N-1, math.ceil(K / 2))
    #print("Parent is {0}".format(parent))
    if parent == 1:
        if K & 0x1:
            return 1
        else:
            return 0
    else:
        if K & 0x1:
            return 0
        else:
            return 1
