#include <stdio.h>
#include <cs50.h>

// prototype
int get_n(void);
void meow(int times);

int main(void)
{
    // Get the number of times to meow
    int n = get_n();
    meow(n);
}

int get_n(void)
{
    // Separate getting n from the user
    int n;
    do
    {
        n = get_int("What's n? ");
    }
    while (n < 0);
    return n;
}

void meow(int times)
{
    // Meow some number of times
    for (int i = 0; i < times; i++)
    {
        printf("Meow\n");
    }
}