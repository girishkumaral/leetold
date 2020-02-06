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

#binaryString("", 2)
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

allsubsets("", l)
