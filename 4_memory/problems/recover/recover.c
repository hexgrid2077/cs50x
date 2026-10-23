#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef unsigned char BYTE; // Stole this code from cp.c
const int HEADER_SIZE = 32; // Assuming each of the four bytes is 8 bits.
uint8_t buffer[512];
uint8_t signature[] = {0xff, 0xd8, 0xff, 0xef}; // Do I need to run an array for the possible combos of the 4th byte?

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
    // TODO: Look for the beginning of a JPEG file. Use the HEADER_SIZE variable here.
    BYTE b;
    while (fread(buffer, 1, 1, cardfile) != 0); // Using 1 as the number of elements and size because we'll go for the header size.
    {
    fread(&b, HEADER_SIZE, 1, buffer);
    printf("If it's a jpeg, create a new file.\n");
    // printf("%i\n", buffer[i]);
    }
    fclose(cardfile);
    // pdf.c in Section is the best example here.
    // TODO: Do we have to do something about the 0xea 0xeb etc like have an array of the 16 possible combinations of the last hex letter?
    
    // TODO: while there' still data left to read on the memory card
        // TODO: Go 512B bytes, we can use the first problem for the byte sizes that was in the header for pdf or something. TODO: Create JPEGs from the data.
        // Use fread and fwrite
}
