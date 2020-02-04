import random

def quickselect(arr, low, high, k):
    print("called with low {0} high {1}".format(low, high))
    if (low >= high):
        return
    small=low
    big=low+1
    pindex = random.randrange(low, high)
    arr[small], arr[pindex] = arr[pindex], arr[small]
    while big <= high:
        if arr[big] < arr[low]:
            small+=1
            arr[small],arr[big] = arr[big], arr[small]
        big+=1
    arr[small], arr[low] = arr[low], arr[small]

    if small < k:
        quickselect(arr, small+1, high, k)
    elif small > k:
        quickselect(arr, low, small-1, k)
    else:
        return


x=[15, -1, 3, -1, 100, 0]

quickselect(x, 0, len(x)-1, 3)
print(x)
print(x[3])
