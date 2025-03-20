size = 56000
partition = [0]*(size+1)
partition[0] = 1

def dp(size):
    for coin in range(1, size+1):
        for num in range(1, size+1):
            if(num-coin >= 0):
                partition[num] += partition[num-coin]

dp(size)
n = 1000000
for i in range(1, len(partition)):
    if(partition[i]%n == 0):
        print(i)
        break
