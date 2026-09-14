#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.");
        return 1;
    }

    FILE *pdf = fopen(argv[1], "r");

    __uint8_t buffer[4];
    __uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    fread(buffer, 1, 4, pdf);
    fclose(pdf);

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Not a PDF.\n");
            return 0;
        }
    }
    printf("Likely a PDF!\n");
    return 0;
}

/* 
Checks whether a file, passed as a command line argument is likely a PDF.
All PDFs begin with a 4 byte sequence:
0x25 0x50 0x44 0x46

$ ./pdf text.pdf
LIkely a PDF!
$ ./pdf test.jpg
Hm, not a PDF.
*/