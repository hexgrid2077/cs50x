#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 1. setup an array of each letter with the points for it
    //  Like two dimension array? But one will be a char and one will be an int. A and 1.
    // Pretty sure we will have to map it out like an ascii thing so 66 (A) and Z is 90
    // https://blog.eduprintable.com/
    int alphabet[2][2] = { {65, 1}, {66, 2} };
    
    char letter = 'A';
    printf("%i", letter);

    // How many points is A? Get it off the array.
    int messed = 'A';
    printf("%i", messed);
    // This has to be a for loop that loops through the array looking for the number 65.



    // Don't forget to make it lowercase. Use TOUPPER from ctype.h
    // 2. Loop through the word for player 1 and add the points up. Make sure this works first
    // 3. If that works then add the player 2 input and evaluate points. Easy peasy.
    printf("\n");
}

 


