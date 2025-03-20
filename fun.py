def NoOfDivisors(n):
    ans = 1
    i = 2
    while(n !=1):
        if(n%i == 0):
            k = 0
            while(n%i == 0):
                k=k+1
                n = n//i
            ans = ans*(k+1)
        i=i+1
    return ans

num = 13082761331670030
LIMIT = 614889782588491410
limitOfDivisors = 8000000
count = 0
K = 1


while(count<=limitOfDivisors):
    count = NoOfDivisors((num*K)*(num*K))
    print(num*K, count)
    if(count > limitOfDivisors):
        print(num*K, count)
        break
    K+=1
