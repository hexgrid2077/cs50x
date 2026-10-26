#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int max = 0;
    int number_of_elements = get_int("Number of elements: ");

    for (int i = 0; i < number_of_elements; i++)
    {
        int element = get_int("Element %i: ", i);
        if (element > max)
        {
            max = element;
        }
    }
    printf("The max value is %i.\n", max);
    return 0;
}
