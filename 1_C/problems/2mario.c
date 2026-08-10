#include <stdio.h>
#include <cs50.h>

int get_legit_height();
void print_spaces(int spaces);
void print_bricks(int bricks);

int main(void)
{   
    int height = get_legit_height();
    printf("\n"); // Keep it fresh
    int bricks = 1;
    int spaces = (height - bricks);
    while (bricks <= height)
    {
        // printf("Bricks: %i\t", bricks);
        // printf("Spaces: %i\n", spaces);
        print_spaces(spaces);
        print_bricks(bricks);
        printf("  "); // Space between the bricks
        print_bricks(bricks);
        print_spaces(spaces);
        printf("\n"); // Newline
        bricks++;
        spaces--;
    }
    printf("\n");
}

int get_legit_height()
{
    int height = 0;
    while (height <= 0 || height > 10)
    {
        int height = get_int("How tall do you want this bastard? ");
        if (height <= 0 || height > 10)
        {
            continue;
        }
        else
        {
            return height;
        }
    }
    return height;
}

void print_spaces(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }
}

void print_bricks(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}