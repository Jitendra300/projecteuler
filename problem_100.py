from math import floor, sqrt

def expr(n):
    return sqrt((n+floor(sqrt(2)*n*floor(sqrt(2)*n)))/2)

def soln(n):
    return (0.5) + (sqrt(2*n**2 - 2*n + 1))/2

i = 31509019102
limit = 10**13

while(i < limit):
    if(i == expr(i)):
        print(i, end=" -> ")
        print(soln(i))

    i+=1
