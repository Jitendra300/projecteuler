f = open("INPUT_FILE/0022_names.txt", "r")
data = f.read().split(",")

for i in range(0, len(data)):
    data[i] = data[i][1:(len(data[i])-1)]

data.sort() # this sorts the array which is filled with names
score = 0

for i in range(0, len(data)):
    curr_score = 0
    for j in data[i]:
        curr_score += (ord(j)-64)
    curr_score *= (i+1)
    score  += curr_score

print(score)
f.close()
