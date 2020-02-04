import heapq


def heapsort(arr):
    result=[]
    heapq.heapify(arr)
    while len(arr):
        result.append(heapq.heappop(arr))
    return result



x=[1, -15, 2, 16, -100, 2]

print(heapsort(x))
