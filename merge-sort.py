def merge(arr, lowL, highL, lowR, highR):
    i = lowL
    j = lowR
    aux = []
    k = 0
    while i <= highL and j <= highR:
        if arr[i] <= arr[j]:
            aux.append(arr[i])
            k+=1
            i+=1
        else:
            aux.append(arr[j])
            k+=1
            j+=1

    while i <= highL:
        aux.append(arr[i])
        k+=1
        i+=1

    while j <= highR:
        aux.append(arr[j])
        k+=1
        j+=1

    i = 0

    while i < k:
        arr[lowL] = aux[i]
        lowL+=1
        i+=1





def mergesort(arr, low, high):

    if low >= high:
        return

    mid = ((high-low) // 2) + low

    mergesort(arr, low, mid)
    mergesort(arr, mid+1, high)

    merge(arr, low, mid, mid+1, high)


a = [-1, -6, 20, -15, 100, 0, 1]
mergesort(a, 0, len(a)-1)

print(a)
