#include <cs50.h>
#include <stdio.h>

int fib(int n);

int main(void)
{
    int n = get_int("Fibonacci of: ");
    printf("The %i Fibonacci number is %i\n", n, fib(n));
}

// Takes the fibonacci number you want, returns that
int fib(int n)
{
    // Base case - when to stop
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    return fib(n - 1) + fib(n - 2);
}