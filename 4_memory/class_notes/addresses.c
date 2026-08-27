#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n; // The canonical way to declare a pointer
    printf("%p\n", p);
}