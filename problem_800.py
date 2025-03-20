# all important modules
from math import sqrt, log10

# function which checks whether a given number is prime or not!
def isprime(n):
    for i in range(3, int(sqrt(n))+1, 2):
        if(n%i == 0):
            return False
    return True

primes = [2]

N = 800800
exponent = 800800
ans = 0
comparisonNum = exponent*log10(N)

for n in range(3, 16000100, 2):
    if(isprime(n)):
        primes.append(n)

i = 0
j = len(primes) - 1
while(j>i):
    ourNum = primes[i]*log10(primes[j]) + primes[j]*log10(primes[i])
    if(ourNum < comparisonNum):
        ans += j-i
        i+=1
    else:
        j-=1

print(ans)

