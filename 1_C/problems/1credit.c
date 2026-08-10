#include <stdio.h>

long card = 5812345678912347;
int tempnum, starting_digit;

int get_digits(long card);

int main(void)
{
    int digits = get_digits(card);
    printf("digits: %i\n", digits);
}

int get_digits(long card)
{
    int digits = 0;
    while (digits <= 16)
    {
        if (card >= 10)
        {
            int tempnum = card % 10;
            card -= tempnum;
            card /= 10;
            digits+= 1;
            // printf("Tempnum: %i\n", tempnum);
        }
        else
        {
            int starting_digit = card % 10;
            printf("starting digit: %i\n", starting_digit);
            digits += 1;
            break;
        }
    }

    if (starting_digit == 3 && digits == 15)
    {
        printf("AMERICAN EXPRESS");
    }
    else if (starting_digit == 5 && digits == 16)
    {
        printf("MASTERCARD");
    }
    else if (starting_digit == 4 && (digits == 13 || digits == 16))
    {
        printf("VISA");
    }
    printf("FUCK. Digits %i\n", starting_digit);
    return digits;
}

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