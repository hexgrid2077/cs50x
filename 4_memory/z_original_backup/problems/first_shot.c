#include <stdio.h>
#include <cs50.h>

int main(int argc, char * argv[])
{
    // Check if there are four arguments, the program, two files and a multiplier
    if (argc == 4)
    {
        printf("There are %i arguments. Good, proceed.\n", argc);
        // do the check wav header function.

        // Copy the wav form HEADER from input.wav to output.wav
        // copy the other bytes after multiplied by the factor.
        
    }
    else
    {
        printf("You need to use this format: ./volume.c input.wav output.wav 2.0\n");
    }

}

/* 
Start with the command line arguments:
./volume input.wav output.wav 2.0

where 2.0 is the volume multiplier.

Header files should use uint8_t for the first 44 bytes,
..and the sound data after should be uint16_t for the signed integers.

fread and fwrite



*/