#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_number = 4003612345678414; // replace with get_long once this works
    long last = card_number % 10;
    printf("Last: %ld\n", last);

    long second_last = ((card_number %100) - last)/10;
    printf("2nd Last: %ld\n", second_last);

    long third_last = ((card_number%1000) - last - second_last)/100;
    printf("3rd Last: %ld\n", third_last);
    // Add a "place" like 10, 100, 1000, 10000 so multiply by 10 each go.
    // Add a cumulative amount removed so we don't have to go -last - second last - third last
    // Add a digit counter on each cycle so we can count up how many digits as well!



    // write a loop to get the digits

    // get a credit card number
    // use the % 10 to get the last digit of each thing and mimic them (2ndlast, 3rdlast, 4thlast etc)
    // add up the credit card length
    // add them up for the checksum
}
