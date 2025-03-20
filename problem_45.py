from math import sqrt

def ispentagonal(n):
    num = ((1+sqrt(1+24*n))/6)
    return num == (int(num))
def ishexagonal(n):
    num = ((1+sqrt(1+8*n))/4) 
    return  num == (int(num))

i = 150
run = True
while(run):
    # if(ispentagonal(i) and ishexagonal(i)):
    hnum = i*(2*i - 1)
    if ((1+sqrt(1+24*hnum))/6) ==  int((1+sqrt(1+24*hnum))/6):
        print("done: ", i)
        run = False
        break
    i+=1
    # print(i)
