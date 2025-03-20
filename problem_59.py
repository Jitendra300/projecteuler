f = open("INPUT_FILE/0059_cipher.txt")
data = f.read().split(",")

for i in range(0, len(data)):
    data[i] = int(data[i])

SIZE = len(data)

def letterFrequency(character, new_data):
    count = 0
    for i in range(0 ,SIZE):
        if(chr(new_data[i]) == character):
            count+=1
    return count

# for natural english language it would be more than 0.0686
def index_of_coincidence(new_data):
    IC = 0.0
    for i in range(65, 123):
        ith_frequency = letterFrequency(chr(i), new_data)
        IC += (ith_frequency*(ith_frequency-1))/(SIZE*(SIZE-1))
    return IC

best_value = [0,0,0] #answer is 101, 120, 112 or exp
current_IC = 0

for x in range(97, 123):
    for y in range(97, 123):
        for z in range(97, 123):
            new_data = []
            for i in range(0, len(data)):
                if(i%3 == 0):
                    new_data.append(data[i]^x)
                elif(i%3 == 1):
                    new_data.append(data[i]^y)
                elif(i%3 == 2):
                    new_data.append(data[i]^z)

            this_IC = index_of_coincidence(new_data)
            if(this_IC >= current_IC):
                current_IC = this_IC
                best_value = [x,y,z]

print("Key:", end="")
print(chr(best_value[0]), chr(best_value[1]), chr(best_value[2]), sep="")

ans = 0
print("Original Text: ")
for i in range(0, len(data)):
    if(i%3 == 0):
        print(chr(data[i]^best_value[0]), end="")
        ans += data[i]^best_value[0]
    elif(i%3 == 1):
        print(chr(data[i]^best_value[1]), end="")
        ans += data[i]^best_value[1]
    elif(i%3 == 2):
        print(chr(data[i]^best_value[2]), end="")
        ans += data[i]^best_value[2]

print("\n")
print("Sum of Ascii Code of Original Text   :", ans)

f.close()
