#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            double averageColor = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            image[i][j].rgbtRed = (int) round(averageColor);
            image[i][j].rgbtGreen = (int) round(averageColor);
            image[i][j].rgbtBlue = (int) round(averageColor);
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    Formula taken from https://dyclassroom.com/image-processing-project/how-to-convert-a-color-image-into-sepia-image

    tr = 0.393R + 0.769G + 0.189B
    tg = 0.349R + 0.686G + 0.168B
    tb = 0.272R + 0.534G + 0.131B

    If tr > 255 then r = 255 else r = tr
    If tg > 255 then g = 255 else g = tg
    If tb > 255 then b = 255 else b = tb
    */

   for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            double tr = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            double tg = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            double tb = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            if(tr > 255) {
                image[i][j].rgbtRed = 255;
            } else {
                image[i][j].rgbtRed = (int) round(tr);
            }

            if(tg > 255) {
                image[i][j].rgbtGreen = 255;
            } else {
                image[i][j].rgbtGreen = (int) round(tg);
            }

            if(tb > 255) {
                image[i][j].rgbtBlue = 255;
            } else {
                image[i][j].rgbtBlue = (int) round(tb);
            }
        }
   }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width / 2; j++) {
            int tempRedPos = image[i][width - 1 - j].rgbtRed;
            int tempGreenPos = image[i][width - 1 - j].rgbtGreen;
            int tempBluePos = image[i][width - 1 - j].rgbtBlue;

            image[i][width - 1 - j].rgbtRed = image[i][j].rgbtRed;
            image[i][width - 1 - j].rgbtGreen = image[i][j].rgbtGreen;
            image[i][width - 1 - j].rgbtBlue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = tempRedPos;
            image[i][j].rgbtGreen = tempGreenPos;
            image[i][j].rgbtBlue = tempBluePos;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(i == 0 || i == height - 1) {

            }
        }
    }
}
