from decimal import *
from math import sqrt

getcontext().prec = 105

n = 2 # already given for 2
ans = 0
LIMIT = 100
while n<LIMIT:
    if(sqrt(n) != int(sqrt(n))):
        string_approx = str(Decimal(n).sqrt())
        for i in range(0, 101):
            if(i == 1): continue
            # print(string_approx[i], end="")
            ans += int(string_approx[i])
        # print()
    n+=1

print(ans)
