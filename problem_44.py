from math import sqrt, fabs

def ispentagonal(n):
    return ((1+sqrt(1+24*n))/6) == (int((1+sqrt(1+24*n))/6))

def pentagonal(n):
    return  n*(3*n-1)/2

run = True
n = 1
while(run):
    d = 1
    while(n-d > 0):
        if(ispentagonal(pentagonal(n)-pentagonal(n-d)) and ispentagonal(pentagonal(n)+pentagonal(n-d))):
            print(pentagonal(n), pentagonal(n-d), n)
            print(fabs(pentagonal(n)-pentagonal(n-d)))
            run = False
            break
        d+=1
    n+=1


