# https://projecteuler.net/problem=99
from math import log10

lis = list()
f = open("INPUT_FILE/0099_base_exp.txt") # file object

data = f.read() # reading data from file
data = data.split("\n")

# refining data
for i in data:
    a,b = i.split(",")
    a = int(a)
    b = int(b)
    lis.append((a,b))

line = 0
ans = 0

# calculating solution
for i in range(0, len(lis)):
    num = lis[i][1]*log10(lis[i][0])
    if(ans < num):
        ans = num
        line = i+1

print(line)

f.close() # close file object
