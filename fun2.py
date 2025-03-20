def Satisfies(n):
    ans = 0
    n2 = n
    while(n2):
        ans += (n2%10)
        n2 = n2//10

    k = 1
    
    if(ans == 1):
        return False

    while(True):
        expression = pow(ans, k)
        if(expression == n):
            return True
            break
        elif(expression > n):
            return False
        k+=1

count = 0
n = 80


while(count < 30):
    if(Satisfies(n)):
        print(n)
        count+=1
    n+=1
