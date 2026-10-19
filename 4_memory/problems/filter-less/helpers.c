#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // TODO: This is where we need to program for this one.
    printf("Fuck fuck fuck!\n");
    printf("image: Fuck I don't know...\nheight: %i\nwidth: %i\n", height, width);
    // Loop over all pixels
    int fakeheight = 2;
    int fakewidth = 2;
    printf("So I must have to loop over this array and then see what each thing looks like.\n");
    for (int i=0; i < fakeheight; i++)
    {
        for (int j=0; j < fakewidth; j++)
        {
            BYTE fuck = image[i][j].rgbtRed;
            printf("image[i][j].rgbtRed %B\n", fuck);

        }
    }
    // Take average of red, green and blur
    // Update pixel values
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
