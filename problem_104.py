def fibonnaci(n): #Finds the nth fibonnaci number
    v1, v2, v3 = 1, 1, 0    # initialise a matrix [[1,1],[1,0]]
    for rec in bin(n)[3:]:  # perform fast exponentiation of the matrix (quickly raise it to the nth power)
        calc = v2*v2
        v1, v2, v3 = v1*v1+calc, (v1+v3)*v2, calc+v3*v3
        if rec=='1':
            v1, v2, v3 = v1+v2, v1, v2  
    return v2

def containsAllDigit(s):
    for i in range(49, 58):
        if(chr(i) not in s):
            return False
    return True

k = 3
notFound = True
while notFound:
    if(containsAllDigit(str(fibonnaci(k)%1000000000))):
        s = str(fibonnaci(k))
        if(containsAllDigit(s[0:9])):
            print(k)
    k+=1
