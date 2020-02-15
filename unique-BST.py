
'''

Structurally unique binary tree.

'''

R=[]
l=[]
n=0
T=0
RC=0

def pruneRec(i, j, N):
    global n
    y=0
    if (i == N):
        uniquebinarytreeHelp(i, j, N)
    else:
        if l[j] == None:
            while l[j] == None and j < n:
                l.append(None)
                n+=1
                y+=1
                j+=1
            if j < n and l[j] != None:
                uniquebinarytreeHelp(i, j, N)
                while y > 0:
                    n-=1
                    l.pop(n)
                    y-=1
            else:
                print("Crap")
        else:
            uniquebinarytreeHelp(i, j, N)

def uniquebinarytreeHelp(i, j, N):
    global T
    global n
    global RC

    RC+=1
    two = 0
    #print(i, j, l)
    if (i == N):
        #print("copying result {0}".format(l))
        #R.append(l.copy())
        T+=1
    else:
        if i > 1 and (l[j] == None):
            l.append(None)
            l.append(None)
            n+=1
            n+=1
            uniquebinarytreeHelp(i, j+1, N)
            n-=1
            l.pop(n)
            n-=1
            l.pop(n)
        else:
            if i + 2 <= N:
                i+=1
                l.append(i)
                n+=1
                i+=1
                l.append(i)
                n+=1
                #uniquebinarytreeHelp(i, j+1, N)
                pruneRec(i, j+1, N)
                n-=1
                l.pop(n)
                n-=1
                l.pop(n)
                i-=1
                i-=1

            i+=1
            l.append(i)   #left is not None
            n+=1
            if (i < N):
                two = 1
                l.append(None)
                n+=1
            #uniquebinarytreeHelp(i, j+1, N)
            pruneRec(i, j + 1, N)
            n-=1
            l.pop(n)
            if (two == 1):
                n-=1
                l.pop(n)
                two = 0
            i-=1

            i+=1        #right is not None
            l.append(None)
            n+=1
            l.append(i)
            n+=1
            #uniquebinarytreeHelp(i, j+1, N)
            pruneRec(i, j + 1, N)
            n-=1
            l.pop(n)
            n-=1
            l.pop(n)
            i-=1


           # put none to both children and pass on
           # precondition cannot put both null of all my peers to right are None
            y = j
            no = 0
            for x in range(j+1, n):
                if l[x] != None:
                    no = 1
                    break

            if (no == 1):
                l.append(None)
                l.append(None)
                n += 1
                n += 1
                #uniquebinarytreeHelp(i, j + 1, N)
                pruneRec(i, j + 1, N)
                n -= 1
                l.pop(n)
                n -= 1
                l.pop(n)



'''
        if l[j] == None:
            l.append(None)
            n+=1
            l.append(None)
            n+=1
            uniquebinarytreeHelp(i, j+1, N)
            n-=1
            l.pop(n)
            n-=1
            l.pop(n)
'''

def uniquebinarytree(N):
    global n
    if (N == 0):
        return []
    elif (N == 1):
        return [1]
    else:
        l.append(1)
        n+=1
        uniquebinarytreeHelp(1, 0, N)
        return T

#uniquebinarytree(12)
#for x in R:
#    print(x)

#print(T)

#print(RC)


mem = [-1 for x in range(0,17)]

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

print(how_many_BSTs(10))
