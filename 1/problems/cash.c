#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int quarters = 0, dimes, nickels, pennies, change;  
    change = -1;
    while (change < 0 || change > 99)
    {
        change = get_int("Change owed: ");
    }

    // Check Quarters
    int remainder = change % 25;
    quarters = (change - remainder)/25;
    // printf("Quarters: %i\n", quarters);

    // Check Dimes
    change = remainder;
    remainder = change % 10;
    dimes = (change - remainder)/10;
    // printf("Dimes: %i\n", dimes);

    // Check Nickels
    change = remainder;
    remainder = change % 5;
    nickels = (change - remainder)/5;
    // printf("Nickels: %i\n", nickels);

    // Check Pennies
    change = remainder;
    remainder = change % 1;
    pennies = (change - remainder)/1;
    // printf("Pennies: %i\n", pennies);
    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

    // 1. Start with 75 cents
    // 2. Once that thing works to 4 coins then you can do the user prompt stuff
    // 3. user prompt just has to be between 0 and 100
    // 4. Run the tests: https://cs50.harvard.edu/x/psets/1/cash/