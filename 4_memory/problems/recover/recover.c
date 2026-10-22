#include <stdio.h>
#include <stdlib.h>
 
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
    // TODO: If the image can't be opened for reading (checking the bytes) print a message and return 1
    // TODO: Look for tghe beginning of a JPEG file.
    
    // TODO: while there' sstill data left to read on the memory card
        // TODO: Create JPEGs from the data.
    
    
}
