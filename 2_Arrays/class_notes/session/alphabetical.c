#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool print_stuff(string stuff);

int main (void)
{
    string input = get_string("Input: ");
    if (print_stuff(input))
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }
}

bool print_stuff(string stuff)
{
    string prev_char;
    string current_char;
    for (int i = 0, n = strlen(stuff); i < n; i++)
    {
        if (stuff[i] > stuff[i-1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}