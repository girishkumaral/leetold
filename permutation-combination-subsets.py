def binaryString(S, n):
    if n > 1:
        binaryString("0"+S, n-1)
        binaryString("1"+S, n-1)
    else:
        print("0"+S)
        print("1"+S)


def decimalString(S, n):
    if n > 1:
        for i in range(10):
            decimalString(str(i)+S, n-1)
    else:
        for i in range(10):
            print(str(i)+S)

#binaryString("", 4)
#decimalString("",4)

def permutationString(S, n, arr):
    y = set()
    if (len(S) == n):
        print(S)
    else:
        for j in range(len(arr)):
            if arr[j] not in y:
                permutationString(S+arr[j], n, arr[:j]+arr[j+1:])
                y.add(arr[j])

l = ['a', 'b', 'c']

#for j in range(len(l)):
#    permutationString("", j, l)



def allsubsets(s, arr):
    if (len(arr) == 0):
        print(s)
    else:
        allsubsets(s, arr[1:])
        allsubsets(s+arr[0], arr[1:])

#allsubsets("", l)


l=['a','b','c']
used=[0,0,0,0,0,0]
s=[]
j=0
def memOptimizedPermutation():
    global j
    global l
    global s
    global used
    #print(j)
    if(j == len(l)):
        print(s)
    else:
        i = 0
        while i < len(l):
            if not used[i]:
                s.append(l[i])
                j+=1
                used[i] = 1
                memOptimizedPermutation()
                j-=1
                #print("Pop index {0}".format(j))
                s.pop(j)
                used[i] = 0
            i+=1
#memOptimizedPermutation()


i=0
C=[]
num=0
def memoptimizedCombination():
    global i
    global j
    global num
    if (i == len(l)):
        num+=1
        print(C)
    else:
        i+=1
        memoptimizedCombination()
        i-=1
        C.append(l[i])
        i+=1
        j+=1
        memoptimizedCombination()
        j-=1
        i-=1
        C.remove(l[i])


memoptimizedCombination()
print("{0} number of subsets printed".format(num))
