import heapq
def topK(arr, k):
    result = []
    h = []
    s = set()
    for x in arr:
        if x not in s:
            if (len(h) >= k):
                y = heapq.heappop(h)
                if (x > y):
                    heapq.heappush(h,x)
                    s.remove(y)
                    s.add(x)
                else:
                    heapq.heappush(h, y)
            else:
                heapq.heappush(h,x)
                s.add(x)
    while len(h) > 0:
        result.append(heapq.heappop(h))
    return result
