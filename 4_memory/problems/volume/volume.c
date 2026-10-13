// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    BYTE b; // I stole this from cp.c

    // Open files and determine scaling factor
    FILE* input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE* output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        return 1;
    }

    float factor = atof(argv[3]); // What does atof mean? https://manual.cs50.io/3/atof

    // Copy header from input file to output file
    // Use cp.c here for that BYTE buffer stuff.
    
    for(int i = 0; i < HEADER_SIZE; i++)
    {
        // Do the fread here and fwrite
        fread (&b, sizeof(b), 1, input); // While I can read one byte at a time...
        fwrite(&b, sizeof(b), 1, output);
        // printf("%c", b);
        
    }
    printf("\n");

    // Read samples from input file and write updated data to output file
    while(fread(&b, sizeof(b), 1, input)) // Using a while loop this time because we don't know how long the wav is.
    {
        // Once we can get the thing to make sound, then we add the factor math.
        b = b * factor;
        fwrite(&b, sizeof(b), 1, output); // Write each 1 byte chunk.
    }
    
    // Close files
    fclose(input);
    fclose(output);
}
