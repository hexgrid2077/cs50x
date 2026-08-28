#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char* s = get_string("s: ");

    char* t = s;

    t[0] = toupper(*t);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}