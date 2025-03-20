# from math import abs

def findArea(x1,y1,x2,y2,x3,y3):
    return abs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2)/2

# reading files...
f = open("INPUT_FILE/0102_triangles.txt")

data = f.read().split("\n")
data.pop()

lis = []

# making readable data for our problem....
for i in data:
    l = []
    s = i.split(",")
    for j in s:
        l.append(int(j))
    lis.append(l)

ans = 0

for i in lis:
    area = findArea(i[0], i[1], i[2], i[3], i[4], i[5])
    areaA = findArea(0, 0, i[0], i[1], i[2], i[3])
    areaB = findArea(0, 0, i[2], i[3], i[4], i[5])
    areaC = findArea(0, 0, i[4], i[5], i[0], i[1])
    if(area == (areaA+areaB+areaC)):
        ans +=1
        # print(i)

print(ans)

f.close()
