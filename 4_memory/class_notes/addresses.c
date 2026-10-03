#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    printf("%p\n", &s[0]);
    printf("%p\n", s);
    printf("%s\n", s);

    string* t = &s;
    printf("%s\n", *t);
}
