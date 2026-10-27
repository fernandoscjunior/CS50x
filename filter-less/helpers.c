#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            // Grayscale formula
            double formula = (red + green + blue) / 3.0;
            int average = round(formula);

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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            // Sepia Formula
            int sepiaRed = round(red * 0.393 + green * 0.769 + blue * 0.189);
            int sepiaGreen = round(red * 0.349 + green * 0.686 + blue * 0.168);
            int sepiaBlue = round(red * 0.272 + green * 0.534 + blue * 0.131);

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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE buffer = image[i][j];

            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            float count = 0.0;

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighbor_y = y + r;
                    int neighbor_x = x + c;

                    if (neighbor_x >= 0 && neighbor_x < width && neighbor_y >= 0 && neighbor_y < height)
                    {
                        totalRed += copy[neighbor_y][neighbor_x].rgbtRed;
                        totalGreen += copy[neighbor_y][neighbor_x].rgbtGreen;
                        totalBlue += copy[neighbor_y][neighbor_x].rgbtBlue;
                        count++;
                    }
                }
            }

            image[y][x].rgbtRed = round(totalRed / count);
            image[y][x].rgbtGreen = round(totalGreen / count);
            image[y][x].rgbtBlue = round(totalBlue / count);
        }
    }

    return;
}
