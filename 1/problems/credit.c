#include <stdio.h>
#include <cs50.h>
long n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, cumulative;
int digits;
long modulateby = 10;
long card_number = 4003612345678414; // replace with get_long once this works
long process_digit(long card_number, int digits);
long card_update(long current_digit, long card_number);

int main(void)
{
    printf("starting card number: %ld\n", card_number);

    n1 = process_digit(card_number, digits);
    card_number = card_update(n1, card_number);

    n2 = process_digit(card_number, digits);
    card_number = card_update(n2, card_number);

    n3 = process_digit(card_number, digits);
    card_number = card_update(n3, card_number);

    n4 = process_digit(card_number, digits);
    card_number = card_update(n4, card_number);

    n5 = process_digit(card_number, digits);
    card_number = card_update(n5, card_number);

    n6 = process_digit(card_number, digits);
    card_number = card_update(n6, card_number);

    n7 = process_digit(card_number, digits);
    card_number = card_update(n7, card_number);

    n8 = process_digit(card_number, digits);
    card_number = card_update(n8, card_number);

    n9 = process_digit(card_number, digits);
    card_number = card_update(n9, card_number);

    n10 = process_digit(card_number, digits);
    card_number = card_update(n10, card_number);

    n9 = process_digit(card_number, digits);
    card_number = card_update(n9, card_number);

    n10 = process_digit(card_number, digits);
    card_number = card_update(n10, card_number);

    n11 = process_digit(card_number, digits);
    card_number = card_update(n11, card_number);

    n12 = process_digit(card_number, digits);
    card_number = card_update(n12, card_number);

    n13 = process_digit(card_number, digits);
    card_number = card_update(n13, card_number);

    n14 = process_digit(card_number, digits);
    card_number = card_update(n14, card_number);

    n15 = process_digit(card_number, digits);
    card_number = card_update(n15, card_number);

    n16 = process_digit(card_number, digits);
    card_number = card_update(n16, card_number);
}

// TODO pass two variables into this function...
long process_digit(long card_number, int digits)
{
    long current_digit = card_number % 10;
    printf("current_digit: %ld\t", current_digit);
    return current_digit;
}

long card_update(long current_digit, long card_number)
{
    card_number -= current_digit;
    card_number /= 10;
    if (card_number == 0)
    {
        printf("CARD COMPLETE.\n");
        return false;
    }
    else
    {
        printf("Card Number remaining: %ld\n", card_number); // This is not making it outside of the function.
        return card_number;
    }
}

// HELP - Can I smash the two functions together for each n with a void function and no return? Will it modify the global variables?
// Add a digit counter on each cycle so we can count up how many digits as well!
// write a loop to get the digits

// get a credit card number
// add them up for the checksum
// check if last digit starts with 3, 4 or 5

// -------------------------------------------------------------
// American Express
// 15 Digits
// Starts with 34 or 37

// MasterCard
// 16 Digits
// Starts with 51, 52, 53, 54 or 55

// Visa
// 13 & 16 Digits
// Starts with 4