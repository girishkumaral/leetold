str="ababbabbaba"
l=[]
n=0



def ispalendrom(i, j):
    if(i == j):
        return True
    else:
        while(i <= j):
            #print("{0} == {1}".format(str[i], str[j]))
            if str[i] != str[j]:
                return False
            i+=1
            j-=1
        else: return True


def printsubpal(l):
    y = 0
    print("++++++++++++++++")
    for x in l:
        print(str[y:x])
        y = x
    print("++++++++++++++++")


def palendromPartition(i):
    global n
    if (i == len(str)):
        printsubpal(l)
    elif (i > len(str)):
        return
    else:
        for j in range(i, len(str)):
            if(ispalendrom(i, j) == True):
                #print("{0} is a palendrome".format(str[i:j+1]))
                l.append(j+1)
                n+=1
                palendromPartition(j+1)
                n-=1
                l.pop(n)


palendromPartition(0)

