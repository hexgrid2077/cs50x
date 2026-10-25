#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int intcounter = 0;
int* COUNTER = &intcounter;

int main(int argc, char *argv[])
{
    char* new_jpeg_name = malloc(8);
    sprintf(new_jpeg_name, "images/%03i.jpg", *COUNTER);
    FILE* current_jpg = fopen(new_jpeg_name, "w");


    if (argc != 2)     // Do something if they only have one command line argument. It should be filename.raw and that's it.
    {
        printf("ERROR: Usage is ./recover [filename.raw]\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* cardfile = fopen(filename, "r"); // We're calling the filename cardfile.
    if (cardfile == NULL) // Check if the file is valid.
    {
        printf("Cannot open image.\n");
        return 1;
    }

    uint8_t buffer[512];
    // While there's still data left to read on the memory card
    while (fread(buffer, 1, 512, cardfile) == 512) // First have the outside loop that reads 512 byte blocks
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) 
        {
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            {
                fclose(current_jpg);
                // Write to the new image
                *COUNTER = *COUNTER + 1;
                sprintf(new_jpeg_name, "images/%03i.jpg", *COUNTER);
                printf("This is NEW JPEG #%03i or %s\n", *COUNTER, new_jpeg_name);
                FILE* current_jpg = fopen(new_jpeg_name, "w");
                fwrite(buffer, 1, 512, current_jpg);
            }
        }
        else
        {
            // Else: keep writing to the current image.
            //FILE* current_jpg = fopen(new_jpeg_name, "a");
            fwrite(buffer, 1, 512, current_jpg);
        }
    }
    fclose(cardfile);
    fclose(current_jpg);
    free(new_jpeg_name);
}
