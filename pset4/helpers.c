#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

             //grayscale type declaration
            average = round( (image[j][i].rgbtRed + image[j][i].rgbtGreen + image[j][i].rgbtBlue) / (3.000));

            image[j][i].rgbtRed = average;
            image[j][i].rgbtBlue = average;
            image[j][i].rgbtGreen = average;

        }
    }
}

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     int temp[3];
     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            temp[0] =image[i][j].rgbtRed;
            temp[1] =image[i][j].rgbtBlue;
            temp[2] =image[i][j].rgbtGreen;


            image[i][j].rgbtRed = image[i][width - 1 - j ].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j ].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j ].rgbtGreen;

            image[i][width-j-1].rgbtRed = temp[0];
            image[i][width-j-1].rgbtBlue = temp[1];
            image[i][width-j-1].rgbtGreen = temp[2];
        }
    }

}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        float average;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {



        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
