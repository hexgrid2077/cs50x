#include <stdio.h>

int main(void)
{
    int a = 50;
    int *b = &a;

    printf("a: %i\tb: %p\n", a, b);
    printf("By dereferencing, b is also the value of %i\n", *b);
    printf("\nChanging the value of the b pointer location...\n");
    
    *b = 5000;
    printf("a: %i\tb: %p\n", *b, b);
    
}

