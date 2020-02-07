import random
a=[*range(1, 15)]
l=[]
n=0

'''
def Ksumsubset(K, i, j):

    global n
    print("K={0} i={1} j={2} l={3} a={4}".format(K, i, j, l, a[i:j+1]))
    if (i > j):
        return
    elif K == 0:
        print(l)
    else:
        if a[i] == K:
            l.append(a[i])
            print(l)
            l.pop(n)
            return
        if a[i] > K:
            return
        if a[j] == K:
            l.append(a[j])
            print(l)
            l.pop(n)
      #  if a[i] < K:

        if a[i]+a[j] > K:
            Ksumsubset(K, i+1,j-1)   #did not choose but loose last
            l.append(a[i])
            n+=1
            Ksumsubset(K-a[i], i+1, j-1) #chose only one integer loose last integer
            n-=1
            l.pop(n)
        else:
            l.append(a[i])
            n+=1
            Ksumsubset(K-a[i], i+1, j)
            n-=1
            l.pop(n)

            l.append(a[i])
            l.append(a[j])
            n+=2
            Ksumsubset(K-(a[i]+a[j]), i+1, j-1) #chose both
            n-=1
            l.pop(n)
            n-=1
            l.pop(n)
            l.append(a[j])
            n+=1
            Ksumsubset(K-a[j], i+1, j-1)
            n-=1
            l.pop(n)
            l.append(a[i])
            n+=1
            Ksumsubset(K-a[i], i+1, j-1)
            n-=1
            l.pop(n)

a.sort()
print(a)
Ksumsubset(15, 0, len(a)-1)

'''
M=0
NR1=0
def Ksumsubset(K, i):
    global n
    global M
    global NR1

    NR1+=1
    #print("K={0}, i={1} a={2} l={3}".format(K, i, a[i:], l))
    if K == 0:
        M+=1
        print(l)
        return
    if K < 0 or i >= len(a):
        return
    else:
        l.append(a[i])
        n+=1
        Ksumsubset(K-a[i], i+1)
        n-=1
        l.pop(n)
        Ksumsubset(K, i+1)

a.sort()
#Ksumsubset(25, 0)
#print("{0} subsets printed Number of recursive calls {1}".format(M, NR1))

print("+++++")

N=0
NR2=0
def KsumsubsetO(K, i, j):
    global n
    global N
    global NR2

    #print("K={0}, i={1} , j={2} l={3} a={4}".format(K, i, j, l, a[i:j+1]))
    NR2+=1
    if K == 0:
        N+=1
        #print("X {0}".format(l))
        print(l)
        return
    if K < 0 or i > j:
        return
    else:
        while a[j] > K and j > 0:
            if j is -1:
                return
            j-=1
        #print("J is {0}", j)
        if i > j:
            return
        if i == j:
            if a[i] == K:
                l.append(a[i])
                n+=1
                #print("Y{0}".format(l))
                print(l)
                N += 1
                n-=1
                l.pop(n)
            return
        if a[i] == K or a[j] == K:
            if a[i] == K:
                l.append(a[i])
                n+=1
                #print("Z{0}".format(l))
                print(l)
                N += 1
                n-=1
                l.pop(n)
            elif a[j] == K:
                l.append(a[j])
                n += 1
                #print("A{0}".format(l))
                print(l)
                N += 1
                n -= 1
                l.pop(n)

        while a[i]+a[j] > K:
            if j is -1:
                return
            j-=1
        if i >= j:
            return
        #not consider both
        KsumsubsetO(K, i+1, j-1)
        #consider both
        l.append(a[i])
        l.append(a[j])
        n+=1
        n+=1
        KsumsubsetO(K-(a[i]+a[j]), i+1, j-1)
        n-=1
        l.pop(n)
        n-=1
        l.pop(n)
        l.append(a[i])
        n+=1
        KsumsubsetO(K-a[i], i+1, j-1)
        n-=1
        l.pop(n)
        l.append(a[j])
        n+=1
        KsumsubsetO(K-a[j], i+1, j-1)
        n-=1
        l.pop(n)
#print(a)


KsumsubsetO(25, 0, len(a)-1)
print("{0} subsets printed Number of recursive calls {1}".format(N, NR2))
