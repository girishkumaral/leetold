import random

def qsort(arr, low, high):

    small = low
    big = low+1

    if (low >= high):
        return

    pindex = random.randrange(low,high)

    arr[small], arr[pindex] = arr[pindex], arr[small]

    while big <= high:
        if arr[big] < arr[low]:
            small += 1
            arr[small],arr[big] =arr[big],arr[small]
        big += 1

    arr[small],arr[low] = arr[low],arr[small]

    qsort(arr, low, small-1)
    qsort(arr, small+1, high)



def caller():
    x = [18, -1, 16, 17, 18]
    qsort(x,0, len(x)-1)
    print(x)


caller()
