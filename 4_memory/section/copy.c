#include <stdio.h>

int main(void)
{
    FILE *input = fopen("in.txt", "r");
    if (input == NULL)
    {
        perror("Failed to open in.txt");
        return 1;
    }
    FILE *output = fopen("out.txt", "w");
    if (output == NULL)
    {
        perror("Failed to open out.txt");
        fclose(input);
        return 1;
    }
    char c;
    while (fread(&c, sizeof(char), 1, input) != 0)
    {
        fwrite(&c, sizeof(char), 1, output);
    }
}