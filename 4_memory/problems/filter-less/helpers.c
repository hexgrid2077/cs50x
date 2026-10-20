#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            // Take average of red, green and blur
            int total = red + green + blue;
            int average = total / 3;

            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            BYTE originalRed = image[i][j].rgbtRed;
            BYTE originalGreen = image[i][j].rgbtGreen;
            BYTE originalBlue = image[i][j].rgbtBlue;

            // Use the Sepia algorithm provided in the docs:
            int sepiaRed = (0.393 * originalRed) + (0.769 * originalGreen) + (0.189 * originalBlue); 
            int sepiaGreen = (0.349 * originalRed) + (0.686 * originalGreen) + (0.168 * originalBlue); 
            int sepiaBlue = (0.272 * originalRed) + (0.534 * originalGreen) + (0.131 * originalBlue); 

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            // Update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
   return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Swap pixels
            int new_loc = width - j;

            // Place in oppsite side
            // image[i][new_loc].rgbtRed = image[i][j].rgbtRed;
            // image[i][new_loc].rgbtGreen = image[i][j].rgbtGreen;
            // image[i][new_loc].rgbtBlue = image[i][j].rgbtBlue;

            // Tried flipping it around but it looks the same.
            image[i][j].rgbtRed = image[i][new_loc].rgbtRed;
            image[i][j].rgbtGreen = image[i][new_loc].rgbtGreen;
            image[i][j].rgbtBlue = image[i][new_loc].rgbtBlue;
            // TODO: I am really stuck here. I need to think about how the pixels get laid out.
            // TODO: The issue is it's mirroring from the center so not the other side. I wonder if using the total width was the way.
            // TODO: The problem is that it's overwriting everything by the time it gets to the other end.
            // May be just do it on paper in like a 5 or 10 pixel graph just to see how you'd do it.
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
