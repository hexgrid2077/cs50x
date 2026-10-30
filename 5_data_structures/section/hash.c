#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int hash(char* word);

int main(void)
{
    char* word = get_string("Word: ");
    printf("Hash value: %i\n", hash(word));
}

int hash(char* word)
{ 
    // Not 2 letters
    if (word == NULL || strlen(word) < 2)    
    {
        return -2;
    }

    char c = word[0];
    char c1 = word[1];

    if (isalpha(c))
    {
        c = toupper(c);
        c1 = toupper(c1);
        // AC -> 2 BB -> 101
        return (c - 'A') * 100 + c1 - 'A';
    }
    return -1;
}
