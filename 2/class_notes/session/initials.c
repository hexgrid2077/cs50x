#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Argc is %i\n", argc);
    for (int i = 1; i < argc; i++ )
    {
        printf("%c", argv[i][0]);
    }
    printf("\n");
}