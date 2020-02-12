# Complete the function below.

R=[]

def helper(i, n, k, l):
    
    #print(i, n, k, l)
    if (i > n or k < 0):
        return
    
    if (i == n and k == 0):
        #print("Found valid {0}".format(l))
        R.append(""+l)
        return
    elif (i == n):
        #print("Invalid {0}".format(l))
        return
    
    if (i == 0):
        #print("Pushed ( to list")
        
        helper(i+1, n, 1, l+"(")
        return
    
    #print("Pushed ( to list {0}".format(l+"("))
    
    if (k + 1 < ((n // 2) +1)):
        helper(i+1, n, k+1, l+"(")
    
   
    #print("Popped ( to list {0}".format(l))
    
    
    #print("Pushed ) to list {0}".format(l+")"))
    if (k - 1 >= 0):
        helper(i+1, n, k-1, l+")")
    
    
    #print("Popped ) to list {0}".format(l))
    
    return
    
    
    
    
def find_all_well_formed_brackets(n):
    if (n == 0):
        return []
    helper(0, 2 * n, 0, "")
    #print(R)
    return R
