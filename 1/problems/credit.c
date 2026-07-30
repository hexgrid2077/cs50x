#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number = 4003600000000014; // replace with get_long after
    long last = card_number % 10;
    printf("Last: %ld\n", last);

    long second_last = ((card_number %100) - last)/10;
    printf("2nd Last: %ld\n", second_last);

    long third_last = 
    // write a loop to get the digits
    // get a credit card number
    // use the % 10 to get the last digit of each thing and mimic them (2ndlast, 3rdlast, 4thlast etc)
    // add up the credit card length
    // add them up for the checksum

}
