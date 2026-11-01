height = int(input("Height: "))

for i in range(0, height):
    j = i+1
    k = height - i
    print((" "*k), ("#"*j), (""), ("#"*j), (" "*k))
