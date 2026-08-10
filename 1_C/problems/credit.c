#include <stdio.h>
#include <cs50.h>
long n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, cumulative, evens;
int digits;
long modulateby = 10;
long card_number = 4003600000000014; // replace with get_long once this works

long process_digit(long card_number);
long card_update(long current_digit, long card_number);
long checksum_evens(long n2, long n4, long n6, long n8, long n10, long n12, long n14, long n16);

int main(void)
{
    printf("starting card number: %li\n", card_number);

    n1 = process_digit(card_number);
    card_number = card_update(n1, card_number);

    n2 = process_digit(card_number);
    card_number = card_update(n2, card_number);

    n3 = process_digit(card_number);
    card_number = card_update(n3, card_number);

    n4 = process_digit(card_number);
    card_number = card_update(n4, card_number);

    n5 = process_digit(card_number);
    card_number = card_update(n5, card_number);

    n6 = process_digit(card_number);
    card_number = card_update(n6, card_number);

    n7 = process_digit(card_number);
    card_number = card_update(n7, card_number);

    n8 = process_digit(card_number);
    card_number = card_update(n8, card_number);

    n9 = process_digit(card_number);
    card_number = card_update(n9, card_number);

    n10 = process_digit(card_number);
    card_number = card_update(n10, card_number);

    n11 = process_digit(card_number);
    card_number = card_update(n11, card_number);

    n12 = process_digit(card_number);
    card_number = card_update(n12, card_number);

    n13 = process_digit(card_number);
    card_number = card_update(n13, card_number);

    n14 = process_digit(card_number);
    card_number = card_update(n14, card_number);

    n15 = process_digit(card_number);
    card_number = card_update(n15, card_number);

    n16 = process_digit(card_number);
    card_number = card_update(n16, card_number);

    if (n1 == -1)
    {
        digits = 13;
    }
    else if (n15 == -1)
    {
        digits = 14;
    }
    else if (n16 == -1)
    {
        digits = 15;
    }
    else
    {
        digits = 16;
    }
    printf("\nDigits: %i\n", digits);
    long evens = checksum_evens(n2, n4, n6, n8, n10, n12, n14, n16);
    printf("Evens: %li\n", evens);


}

// TODO pass two variables into this function...
long process_digit(long card_number)
{
    long current_digit = card_number % 10;
    printf("current_digit: %li\t", current_digit);
    return current_digit;
}

long card_update(long current_digit, long card_number)
{
    card_number -= current_digit;
    card_number /= 10;
    if (card_number == 0)
    {
        printf("CARD COMPLETE\n");
        card_number = -1;
        return card_number;
    }
    else
    {
        printf("Card Number remaining: %li\n", card_number); // This is not making it outside of the function.
        return card_number;
    }
}

long checksum_evens(long n2, long n4, long n6, long n8, long n10, long n12, long n14, long n16)
{
    if ((n2 * 2) >= 10 && n2 > 0)
    {
        evens += 2;
    }
    else{
        evens += 1;
    }
    if ((n4 * 2) >= 10 && n4 > 0){
        evens += 2;
    }
    else{
        evens += 1;
    }
    if ((n6 * 2) >= 10 && n6 > 0){
        evens += 2;
    }
    else{
        evens += 1;
    }
    if ((n8 * 2) >= 10 && n8 > 0){
        evens += 2;
    }
    else{
        evens += 1;
    }
    if ((n10 * 2 >= 10 && n10 > 0) ){
        evens += 2;
    }
    else{
        evens += 1;
    }
    if ((n12 * 2) >= 10 && n12 > 0){
        evens += 2;
    }
    else{
        evens += 1;
    }
     
    if (n14 != -1 && n14 > 0)
    {
        if ((n14 * 2) >= 10)
        {
            evens += 2;
        }
        else
        {
            evens += 1;
        }
    }
    if (n16 != -1 && n16 > 0)
    {
        if ((n16 * 2) >= 10)
        {
            evens += 2;
        }
        else
        {
            evens += 1;
        }
    }

    return evens;
}

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