def farey_sequence(n: int, descending: bool = False) -> None:
    a, b, c, d = 0, 1, 1, n
    activate = False
    ourcount = 0
    while 0 <= c <= n:
        k = (n + b) // d
        a, b, c, d = c, d, k * c - a, k * d - b
        if(a == 1 and b==2):
            activate = False
            break
        if(activate):
            ourcount+=1
        if(a == 1 and b==3):
            activate = True
    print("Our Fractions: ", ourcount)

n = int(input("Enter Number: "))
farey_sequence(n)
