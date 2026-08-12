// #include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    // int height = get_int("Height: ");
    int height = 4;

    draw(height);
}

void draw(int n)
{
    // Base case -- When to stop running the function
    if (n <= 0)
    {
        return;
    }
    
    // Print a pyramid of height n - 1
    draw(n - 1);

    // Print one more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}