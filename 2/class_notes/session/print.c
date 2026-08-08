#include <cs50.h>
#include <stdio.h>
#include <string.h>

void print_stuff(string stuff);

int main (void)
{
    string input = get_string("Input: ");
    print_stuff(input);
    printf("\n");
}

void print_stuff(string stuff)
{
    for (int i = 0, n = strlen(stuff); i < n; i++)
    {
        printf("%c", stuff[i]);
    }
}