// Modifies the volume of an audio file
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
__uint8_t HEADER[HEADER_SIZE]; 


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    while (fread(&))


    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}

/* 
Start with the command line arguments:
./volume input.wav output.wav 2.0

where 2.0 is the volume multiplier.

Header files should use uint8_t for the first 44 bytes,
..and the sound data after should be uint16_t for the signed integers.

fread and fwrite

*/