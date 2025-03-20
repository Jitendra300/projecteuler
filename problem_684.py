from math import sqrt

fibonacci = [0, 1] + [0]*100

for i in range(2, 91):
    fibonacci[i] = fibonacci[i-1]+fibonacci[i-2]

pMod = 1000000007

def modOperation(base, exponent, mod): 
    if(exponent <= 0):
        return 1
    base = (base)%mod
    result = 1
    while(exponent > 0):
        if(exponent%2 == 1):
            result = (result*base)%mod
        exponent = exponent >> 1
        base  = (base*base)%mod
    return result%mod

ans = 0

"""
S(k) = 6*(10^q - 1) + r((r+3)*10^q - 2) - 9q   where k = 9q + r
here the first expression is A, the second is B and the third is C
"""

def S(q, r):
    A = ((6*(modOperation(10, q, pMod)))%pMod - 1)%pMod
    if(r%2 == 0):
        B = ((r/2)*((((r+3)%pMod)*(modOperation(10, q, pMod)%pMod) - 2)%pMod))%pMod
    else:
        B = ((r)*(((((r+3)/2)%pMod)*(modOperation(10, q, pMod)%pMod) - 1)%pMod))%pMod
    C = ((9)*(q%pMod))%pMod
    return (A+B-C)%pMod

def changeFormatOfNum(n):
    return (n//9, n%9)

for i in range(2,91):
    q, r = changeFormatOfNum(fibonacci[i])
    ans += S(q, r) - 5
    ans %= pMod

print(ans)
