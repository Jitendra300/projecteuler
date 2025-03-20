ones = """zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen""".split()
tens = """zero ten twenty thirty forty fifty sixty seventy eighty ninety""".split()

def f(n):
    if(n == 1000):
        return "onethousand"
    if(n>=100):
        ans = ""
        ans += ones[int(n//100)] + "hundred"
        if(n%100 == 0):
            return ans
        return ans + "and" + f(n%100)
    elif(n>=20):
        ans = ""
        ans += tens[int(n//10)]
        if(n%10 == 0):
            return ans
        return ans + f(n%10)
    else:
        return ones[n]

count = 0
for i in range(1, 1001):
    count += len(f(i))
    # print(i, "->", f(i))
print(count)
