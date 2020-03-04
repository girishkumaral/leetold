#
#Complete the fumction numberOfPaths
#The fumction takes integers 2D integer array, matrix, as parameter.
#
def numberOfPaths(matrix):
    cache = [[float(0) for _ in range(len(matrix[0])+1)] for k in range(len(matrix)+1)]
    rows = len(matrix)
    cols = len(matrix[0])
    modNum = pow(10, 9)+7
    
    if matrix[rows-1][cols-1] == 0:
        return 0
    
    i = rows-1
    while i >= 0:
        j = cols-1
        while j >= 0:
            if i == rows-1 and j == cols-1:
                cache[i][j] = 1
            else:
                if matrix[i][j] == 1:
                    cache[i][j] = (cache[i][j+1] + cache[i+1][j]) % modNum
            j-=1
        i-=1

    #print(cache)
    return int(cache[0][0])

