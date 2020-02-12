# Complete the function below.

def helper(i , arr, k, c):
    
    if (i > 0 and k == 0 and c == 1):
        return True
        
    elif (i >= len(arr)):
        return False
        
    if (helper(i+1, arr, k-arr[i], 1) or helper(i+1, arr, k, 0)):
        return True
    else:
        return False

def check_if_sum_possible(arr, k):
    if (len(arr) == 0):
        return False
        
    if (len(arr) == 1) :
        if (k != arr[0]):
            return False
        else:
            return True
        
    return helper(0, arr, k, 0)
