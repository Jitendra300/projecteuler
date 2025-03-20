from math import log10, floor

iteration = 1
num = 90

def isOurNum(n):
    fullNum = n*log10(2)
    decimalPart = fullNum - floor(fullNum)
    firstFewDigits = str(10**decimalPart).replace(".", "")
    if(firstFewDigits[0:3] == "123"):
        return True
    return False

while(iteration < 678910):
    if(isOurNum(num+196)):
        num+=196
    elif(isOurNum(num+289)):
        num+=289
    elif(isOurNum(num+485)):
        num+=485
    iteration+=1

print(num)
