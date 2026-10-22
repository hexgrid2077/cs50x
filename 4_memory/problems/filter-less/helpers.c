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
        int halfway = width / 2;
        for (int j = 0; j < halfway; j++)
        {
            // Swap pixels
            int Rswapspace;
            int Gswapspace;
            int Bswapspace;
            Rswapspace = image[i][j].rgbtRed;
            Gswapspace = image[i][j].rgbtGreen;
            Bswapspace = image[i][j].rgbtBlue;
            // Now make the left side equal the right.
            image[i][j].rgbtRed = image[i][width - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j].rgbtBlue;
            // Then use the swapspace squares to fill the right.
            // Maybe only go to the middle?
            image[i][width - j].rgbtRed = Rswapspace;
            image[i][width - j].rgbtGreen = Gswapspace;
            image[i][width - j].rgbtBlue = Bswapspace;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Do a loop for each pixel in copy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        // Find the average of the 9 squares including the same square
        int Rtop = copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed;
        int Rmid = copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed;
        int Rbot = copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed;
        int Ravg = ((Rtop + Rmid + Rbot) / 9);
            
        int Gtop = copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen;
        int Gmid = copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen;
        int Gbot = copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen;
        int Gavg = ((Gtop + Gmid + Gbot) / 9);

        int Btop = copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue;
        int Bmid = copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue;
        int Bbot = copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue;
        int Bavg = ((Btop + Bmid + Bbot) / 9);

        // Use that average value for the pixel in 'image' -- The original copy.
        image[i][j].rgbtRed = Ravg;
        image[i][j].rgbtGreen = Gavg;
        image[i][j].rgbtBlue = Bavg;
        }
    }

    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // First get the X kernel
            int RTop = (copy[i - 1][j - 1].rgbtRed  * -1) + (copy[i - 1][j].rgbtRed * 0) + (copy[i - 1][j + 1].rgbtRed * 1);
            int RMid = (copy[i][j - 1].rgbtRed  * -2) + (copy[i][j].rgbtRed * 0) + (copy[i][j + 1].rgbtRed * 2);
            int RBot = (copy[i + 1][j - 1].rgbtRed  * -1) + (copy[i + 1][j].rgbtRed * 0) + (copy[i + 1][j + 1].rgbtRed * 1);

            int GTop = (copy[i - 1][j - 1].rgbtGreen  * -1) + (copy[i - 1][j].rgbtGreen * 0) + (copy[i - 1][j + 1].rgbtGreen * 1);
            int GMid = (copy[i][j - 1].rgbtGreen  * -2) + (copy[i][j].rgbtGreen * 0) + (copy[i][j + 1].rgbtGreen * 2);
            int GBot = (copy[i + 1][j - 1].rgbtGreen  * -1) + (copy[i + 1][j].rgbtGreen * 0) + (copy[i + 1][j + 1].rgbtGreen * 1);

            int BTop = (copy[i - 1][j - 1].rgbtBlue  * -1) + (copy[i - 1][j].rgbtBlue * 0) + (copy[i - 1][j + 1].rgbtBlue * 1);
            int BMid = (copy[i][j - 1].rgbtBlue  * -2) + (copy[i][j].rgbtBlue * 0) + (copy[i][j + 1].rgbtBlue * 2);
            int BBot = (copy[i + 1][j - 1].rgbtBlue  * -1) + (copy[i + 1][j].rgbtBlue * 0) + (copy[i + 1][j + 1].rgbtBlue * 1);

            // Add all the R's, G's and B's to get the image Gx.
            int GxR = RTop + RMid + RBot; 
            int GxG = GTop + GMid + GBot; 
            int GxB = BTop + BMid + BBot; 


            // Then get the Y kernel
            int yRTop = (copy[i - 1][j - 1].rgbtRed  * -1) + (copy[i - 1][j].rgbtRed * -2) + (copy[i - 1][j + 1].rgbtRed * -1);
            int yRMid = (copy[i][j - 1].rgbtRed  * 0) + (copy[i][j].rgbtRed * 0) + (copy[i][j + 1].rgbtRed * 0);
            int yRBot = (copy[i + 1][j - 1].rgbtRed  * 1) + (copy[i + 1][j].rgbtRed * 2) + (copy[i + 1][j + 1].rgbtRed * 1);

            int yGTop = (copy[i - 1][j - 1].rgbtGreen  * -1) + (copy[i - 1][j].rgbtGreen * -2) + (copy[i - 1][j + 1].rgbtGreen * -1);
            int yGMid = (copy[i][j - 1].rgbtGreen  * 0) + (copy[i][j].rgbtGreen * 0) + (copy[i][j + 1].rgbtGreen * 0);
            int yGBot = (copy[i + 1][j - 1].rgbtGreen  * 1) + (copy[i + 1][j].rgbtGreen * 2) + (copy[i + 1][j + 1].rgbtGreen * 1);

            int yBTop = (copy[i - 1][j - 1].rgbtBlue  * -1) + (copy[i - 1][j].rgbtBlue * -2) + (copy[i - 1][j + 1].rgbtBlue * -1);
            int yBMid = (copy[i][j - 1].rgbtBlue  * 0) + (copy[i][j].rgbtBlue * 0) + (copy[i][j + 1].rgbtBlue * 0);
            int yBBot = (copy[i + 1][j - 1].rgbtBlue  * 1) + (copy[i + 1][j].rgbtBlue * 2) + (copy[i + 1][j + 1].rgbtBlue * 1);

            // Add all the R's, G's and B's to get the image Gy.
            int GyR = yRTop + yRMid + yRBot; 
            int GyG = yGTop + yGMid + yGBot; 
            int GyB = yBTop + yBMid + yBBot; 

            // Then combine them with the equate Gx^2 + Gy^2
                // Note - Make sure it's capped at 255.
            int combinedR = (GxR * GxR) + (GyR * GyR);
            if (combinedR > 255)
            {
                combinedR = 255;
            }
            image[i][j].rgbtRed = combinedR;
            
            int combinedG = (GxG * GxG) + (GyG * GyG);
            if (combinedG > 255)
            {
                combinedG = 255;
            }
            image[i][j].rgbtGreen = combinedG;
            
            int combinedB = (GxB * GxB) + (GyB * GyB);
            if (combinedB > 255)
            {
                combinedB = 255;
            }
            image[i][j].rgbtBlue = combinedB;
            // Add this result to each R G and B channel for the pixel.
        }
    }
    return;
}
