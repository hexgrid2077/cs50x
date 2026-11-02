with open("sequences/1.txt", "r") as file:
    seq = file.read()
    print(seq)

pattern = "AGATC"
print(f"{pattern} is {len(pattern)} characters.")

if pattern in seq:
    print("Yes it is in the sequence")

count = 0
for i in range(len(seq)):
    if pattern in seq[i:(i+len(pattern))]:
        count += 1

print(count)
