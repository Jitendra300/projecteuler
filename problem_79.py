f = open("INPUT_FILE/0079_keylog.txt")
data = f.read().split("\n")
data.pop()

# using hand i found answer as 73162890
ans = data[0]

for i in range(1, len(data)):
    

print(ans)
f.close()
