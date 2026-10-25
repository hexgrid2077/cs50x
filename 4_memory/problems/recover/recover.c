#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned char BYTE; // Stole this code from cp.c
const int HEADER_SIZE = 3; // Assuming each of the four bytes is 8 bits.
int COUNTER = 000;

int main(int argc, char *argv[])
{
    // Do something if they only have one command line argument. It should be filename.raw and that's it.
    if (argc != 2)
    {
        printf("ERROR: Usage is ./recover [filename.raw]\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* cardfile = fopen(filename, "r");
    // Check if the file is valid.
    if (cardfile == NULL)
    {
        printf("Cannot open image.\n");
        return 1;
    }

    uint8_t buffer[512];
    // While there's still data left to read on the memory card
    while (fread(&buffer, sizeof(buffer), 1, cardfile) != 0) // First have the outside loop that reads 512 byte blocks
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]) 
        {
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            {
                printf("This is NEW JPEG #%i\n", COUNTER);
                COUNTER = COUNTER + 1;
                // TODO: Write to the new image
                fwrite()
            }
        }
        else
        {
            // TODO: Else: keep writing to the current image.
            printf("Keep writing on the same JPEG\n");
        }
        // printf("%i\n", buffer[i]);
    }
    // Close the memory card
    fclose(cardfile);
}
