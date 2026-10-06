#include <stdio.h>

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    FILE* src = fopen(argv[1], "rb");
    FILE* dst = fopen(argv[2], "wb");
    
    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) // While I can read one byte at a time...
    {
        fwrite(&b, sizeof(b), 1, dst); // Write that byte to the file!
    }

    fclose(src);
    fclose(dst);
}

