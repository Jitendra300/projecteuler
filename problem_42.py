import math

f = open("INPUT_FILE/0042_words.txt", "r")
content = f.read()

l = content.split(",")

count = 0

def isperfectsquare(num):
    return (math.sqrt(num) == int(math.sqrt(num)))

for i in l:
    current = 0
    for j in i:
        if(j == '"' or j == '"'):
            continue
        current += (ord(j)-64)

    if(isperfectsquare(8*current + 1)):
        count+=1

print(count)
