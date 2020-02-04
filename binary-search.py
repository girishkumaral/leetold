def binarySearch(arr, k):

    low = 0
    high = len(arr)
    while low < high:
        mid = ((high - low) // 2) + low
        if arr[mid] < k:
            low = mid+1
        elif arr[mid] > k:
            low = mid-1
        else:
            return mid
    return -1

x = [1, 2, 4, 5, 6, 7, 8, 9, 10, 99]

print("{0} is found at index {1}".format(99, binarySearch(x, 99)))
