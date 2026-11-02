"""
13 digits - Sometimes Visa
15 digits - American Express
16 digits - Mastercard and sometimes VISA

Starting numbers
AMEX - 34 or 37
Mastercard - 51, 52, 53, 54 or 55
"""

passes_algo = True

def main():
    # cardnumber = 4003600000000014
    cardnumber = 1234567890
    lencard = str(cardnumber)
    # print(len(lencard))
    # print(lencard[-16])
    set_16 = [-2, -4, -6, -8, -10, -12, -14, -16]
    newlist = []
    
    for i in range(-2, -(len(lencard))-1, -2):
        newlist.append(int(lencard[i]))
    for i in range(len(newlist)):
        newlist[i] *= 2
    for i in range(len(newlist)):
        if int(newlist[i]) > 9:
            newlist[i] -= 10
            newlist.append(1)

    plainlist = []
    for i in range(-1, -(len(lencard))-1, -2):
        plainlist.append(int(lencard[i]))
    print(sum(newlist))
    print(sum(plainlist))
    totalsum = sum(plainlist) + sum(newlist)
    print(totalsum)
    lastdigit = totalsum % 10
    if lastdigit == 0:
        print("Passed Algorithm")
        passes_algo = True
    else:
        print("Failed Algorithm")
        passes_algo = False

    first_two = int(lencard[0:2])

    if passes_algo == True:
        print(first_two)        
        if (first_two == 34 or first_two == 37) and (len(lencard) == 15):
            print("AMEX")
        elif (51 <= first_two <= 55) and (len(lencard) == 16):
            print("MASTERCARD")
        elif (len(lencard) == 13 or len(lencard) == 16):
            print("VISA")


if __name__ == "__main__":
    main()
