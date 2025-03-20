from math import sqrt, floor

def Soln(num):
    anot = floor(sqrt(num))
    
    a = anot
    N = 0
    D = 1

    previousA = a
    previousN = N
    previousD = D
    alist = []

    while(a != 2*anot):
        N = previousA*previousD - previousN
        D = (num - N*N)/previousD
        a = floor((anot+N)/(D))
        
        alist.append(a)
        
        previousA = a
        previousD = D
        previousN = N

    hlist = [1, anot]
    klist = [0, 1]
    # print(alist)
    i = 2
    aIndex = 0
    while True:
        cur_X = alist[aIndex]*hlist[i-1] + hlist[i-2]
        cur_Y = alist[aIndex]*klist[i-1] + klist[i-2]
        hlist.append(cur_X)
        klist.append(cur_Y)
        if(cur_X**2 - num*(cur_Y**2) == 1):
            return cur_X
            break
        i+=1
        aIndex+=1
        if(aIndex >= len(alist)): aIndex = 0

ans = 2
XValue = 0

for x in range(2, 1001):
    if(sqrt(x) == int(sqrt(x))):
        continue
    y = Soln(x)
    if(XValue < y):
        XValue = y
        ans = x


print(ans)
