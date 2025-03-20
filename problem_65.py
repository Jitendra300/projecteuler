pattern = [2, 1] # this list will contain pattern info

def f():
    numerator = [2] + [0]*99
    for i in range(1, 100):
        numerator[i] = pattern[i]*(numerator[i-1])
        if(i-2<0):
            numerator[i] += 1
        else:
            numerator[i] += numerator[i-2]
    return numerator

# this fills the pattern array till 100th term pattern
for i in range(1, 34):
    pattern.append(i*2)
    pattern.append(1)
    if(i != 33): # don't wanna unnessecaryily fill 101st term...lets just keep it till 100th term
        pattern.append(1)

numerator = f()
last_term = numerator[-1]
sum_of_digits = 0

while(last_term):
    sum_of_digits += last_term%10
    last_term //= 10

print(sum_of_digits)
