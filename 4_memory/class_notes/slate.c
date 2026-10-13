#include <stdio.h>

void swap(int* pa, int* pb);

int main(void) {
    int a = 50;
    int b = 25;

    printf("a: %i\tb: %i\n", a, b);
    printf("Swappin'...\n"); 
    int* pa = &a;
    int* pb = &b;
    // Then do a swap
    swap(&a, &b);
    printf("a: %i\tb: %i\n", a, b);
}

void swap(int* pa, int* pb)
{ 
    int temp;
    // swap them numbaz
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
