#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS_P1, POINTS_P2;
int ALPHA[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1,	8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,
    0,0,0,0,0,0,
    1, 3, 3, 2, 1, 4, 2, 4, 1,	8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int add_points(int alphabet[], string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    int POINTS_P1 = add_points(ALPHA, word1);
    string word2 = get_string("Player 2: ");
    int POINTS_P2 = add_points(ALPHA, word2);
    if (POINTS_P1 == POINTS_P2)
    {
        printf("Tie!\n");
    }
    else if (POINTS_P1 < POINTS_P2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}

int add_points(int alphabet[], string word)
{
    int total_points =0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int point_add = alphabet[word[i]-65];
        total_points += point_add;
    }
    return total_points;
}