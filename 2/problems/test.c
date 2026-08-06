#include <cs50.h>
#include <stdio.h>

void valid_triangle(int a, int b, int c);

int main(void)
{
    int a = get_int("a: ");
    int b = get_int("b: ");
    int c = get_int("c: ");

    valid_triangle(a, b, c);
}

void valid_triangle(int a, int b, int c)
{
    if ((a + b) > c)
    {
        printf("Valid.\n");
    }
    else
    {
        printf("Invalid.\n");
    }
}