#include <stdio.h>
#include <cs50.h>

void horizontal(int row_total);

int main(void)
{
    int row_total = get_int("How many rows wide? ");
    int col_total = get_int("How many columns deep? ");
    for (int col = 0; col < col_total; col++) // <-- This is where you would put the column variable
    {
        // Repeat the layer three times
        horizontal(row_total);
    }
}

void horizontal(int row_total)
{
    // Make a layer of horizontal blocks (We could enhance this by getting the amount from the user)
    for (int row = 0; row < row_total; row++)
        {
            printf("#");
        }   
    printf("\n");
}