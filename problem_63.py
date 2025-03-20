n = 1
count = 0
while(n<10):
    k = 1
    while(len(str(n**k)) == k):
        count+=1
        k+=1
    n+=1
print(count)
