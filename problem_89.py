f = open("INPUT_FILE/0089_roman.txt")

data = f.read().split("\n")

ans = 0

def Optimal(s):
    result = s
    replacements = [
        ('VIIII', "IX"),
        ('IIII', "IV"),
        ("LXXXX", "XC"), 
        ("XXXX", "XL"),
        ("DCCCC", "CM"), 
        ("CCCC", "CD")
    ]
    for old, new in replacements:
        result = result.replace(old, new)
    return result

for i in data:
    if(len(i) > len(Optimal(i))):
        ans += len(i)-len(Optimal(i))

print(ans)

f.close()
