def solve(x):
    h = {}
    result = []
    for a in range(len(x)):
        b,c = x[a].split(" ")
        if b in h:
            if h[b].split(",")[1] < c:
                tmp = h[b]
                #print(str(int(tmp[0])))
                h[b] = str(int(tmp[0])+1)+','+c
                #prit(b+h[b])
            else:
                h[b] = str(int(h[b].split(",")[0])+1)+','+h[b].split(",")[1]
        else:
            h[b] = '1,'+c
            #print(b+h[b])

    for a in h:
        result.append(a+':'+h[a])
    
    return result
