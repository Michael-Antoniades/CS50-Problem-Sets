#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

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
    int blueTot;
    int greenTot;
    int redTot;
    float avg_count;

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            blueTot = 0;
            greenTot = 0;
            redTot = 0;
            avg_count = 0.0;

            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int m = -1; m < 2; m++)
                {
                    if (i + m < 0 || i + m > width - 1)
                    {
                        continue;
                    }

                    blueTot += image[j + k][i + m].rgbtBlue;
                    greenTot += image[j + k][i + m].rgbtGreen;
                    redTot += image[j + k][i + m].rgbtRed;
                    avg_count++;
                }
            }

            // averages the sum to make picture look blurrier
            temp[j][i].rgbtBlue = round(blueTot / avg_count);
            temp[j][i].rgbtGreen = round(greenTot / avg_count);
            temp[j][i].rgbtRed = round(redTot / avg_count);
        }
    }

    //copies values from temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
         RGBTRIPLE temp[height][width];

         for ( int i = 0; i < height; i++)
         {
             for ( int j = 0; j < width; j++){
                 temp[i][j] = image[i][j]; //clone initial image
             }
         }

         int gx_kern[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
         int gy_kern[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};


    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            double gx_red = 0;
            double gx_green = 0;
            double gx_blue = 0;
            //establishes 6 gx/gys we need to calculate for new pixel
            double gy_red = 0;
            double gy_green = 0;
            double gy_blue = 0;
            // counter for secondary 3x3 array row

            for (int k = i -1, row = 0; k <= i + 1; k++ , row++)
            {
                for (int m = j -1, column = 0; m <= j + 1; m++, column++)
                {
                    if (k >= 0 && m >= 0 && k < height && m < width)
                    {
                        gx_blue += (gx_kern[row][column] * temp[k][m].rgbtBlue);
                        gx_green += (gx_kern[row][column] * temp[k][m].rgbtGreen);
                        gx_red += (gx_kern[row][column] * temp[k][m].rgbtRed);
                        // Calculate Gy
                        gy_blue += (gy_kern[row][column] * temp[k][m].rgbtBlue);
                        gy_green += (gy_kern[row][column] * temp[k][m].rgbtGreen);
                        gy_red += (gy_kern[row][column] * temp[k][m].rgbtRed);
                    }
                }
            }

            int sobel_blue = round(sqrt(pow(gx_blue, 2) + pow(gy_blue, 2)));
            int sobel_green = round(sqrt(pow(gx_green, 2) + pow(gy_green, 2)));
            int sobel_red = round(sqrt(pow(gx_red, 2) + pow(gy_red, 2)));


            // Set the new colour values for the iterated pixel and cap at 255 if necessary

            image[i][j].rgbtBlue = (sobel_blue > 255) ? 255 : sobel_blue;
            image[i][j].rgbtGreen = (sobel_green > 255) ? 255 : sobel_green;
            image[i][j].rgbtRed = (sobel_red > 255) ? 255 : sobel_red;
        }

    }
    return;

}
