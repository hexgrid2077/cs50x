import csv
patternlist = []
clientlist = []
with open("databases/small.csv", newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    patternlist = reader.fieldnames
    for row in reader:
        clientlist.append(row)

print(patternlist)
print(clientlist)
