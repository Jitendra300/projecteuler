n = 1010101160
while(True):
    s = str(n*n)
    if(s[0] == '1' and s[2] == '2' and s[4] == '3' and s[6] == '4' and s[8] == '5' and s[10] == '6' and s[12] == '7' and s[14] == '8' and s[16] == '9'):
        print(n)
        break
    n += 10
