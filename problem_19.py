from math import floor

def zellers_congruence(date, month, year):
    if(month <= 2):
        month+=12
        year-=1
    q = date
    m = month
    k = year%100
    j = int(year/100)

    x = (date + floor((13*(m+1))/5) + k + floor((k)/4) + 5 + 6*j)
    x = x%7

    if(x == 0):
        return True
    return False

ans = 0

for i in range(1901, 2001):
    for j in range(1, 13):
        if(j == 2):
            if(i%4 == 0):
                for k in range(1, 30):
                    if(k == 1 and zellers_congruence(k, j, i)):
                        ans +=1
            else:
                for k in range(1, 29):
                    if(k == 1 and zellers_congruence(k, j, i)):
                        ans +=1
        elif(j == 1 or j==3 or j == 5 or j == 7 or j==8 or j == 10 or j == 12):
            for k in range(1, 32):
                if(k == 1 and zellers_congruence(k, j, i)):
                    ans +=1
        else:
            for k in range(1, 31):
                if(k == 1 and zellers_congruence(k,  j, i)):
                    ans += 1

print(ans)
