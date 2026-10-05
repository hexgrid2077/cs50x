// Fails to swap two integers

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    int* px = &x;
    int* py = &y;

    printf("x is %i, y ix %i\n", x, y);
    swap(px, py);
    printf("x is %i, y ix %i\n", x, y);
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

