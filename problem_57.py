def numerator(n1, n2):
    return (2*n2 + n1)
def denominator(n1, n2):
    return (2*n2 + n1)

pell_num = [0,1]
lucas_pell_number = [2,2]

n = 1
count = 0

while n<=1000:
    pell_num.append(numerator(pell_num[n-1], pell_num[n]))
    lucas_pell_number.append(denominator(lucas_pell_number[n-1], lucas_pell_number[n]))
    if(len(str(pell_num[n+1])) < len(str(int(lucas_pell_number[n+1]//2)))):
        # print(int(lucas_pell_number[n+1]/2),"/", pell_num[n+1])
        count += 1
    n+=1

print(count)
