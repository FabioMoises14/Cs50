#include "helpers.h"

BYTE limit_to_255(float value)
{
    if(value > 255)
    {
        return 255;

    }
    return (BYTE)(value + 0.5);
}
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0;  i < height;i++ )
    {
        for(int j = 0; j < width;j++ )
        {

            float average = (image[i][j].rgbtBlue +  image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;        //MEDIA
            BYTE gray = (BYTE)(average + 0.5);          //CONVERTER
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtRed = gray;                 //SETAR O VALOR EM PIXEL
            image[i][j].rgbtGreen = gray;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height;i++)
    {
        for(int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtRed  + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed  + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;        //CALCULO PARA SERPIA
            float sepiaBlue = .272 * image[i][j].rgbtRed  + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;


            image[i][j].rgbtRed = limit_to_255(sepiaRed);
            image[i][j].rgbtBlue = limit_to_255(sepiaBlue);                                        // SETAR O VALOR EM PIXEL
            image[i][j].rgbtGreen = limit_to_255(sepiaGreen);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height;i++)
    {
        for(int j = 0; j < width / 2;j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for(int i = 0;i < height;i++)
    {
        for(int j = 0;j < width;j++)
        {
            copy[i][j] = image[i][j];
        }
    }




    for(int i = 0;i < height;i++)
    {
        for(int j = 0; j < width;j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float counter = 0.0;

            for(int di = -1; di <=1 ; di++)
            {
                for(int dj = -1;dj <=1;dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;

                    if(new_i >= 0 && new_i < height && new_j >= 0 && new_j < width )
                    {
                        sumRed += copy[new_i][new_j].rgbtRed;
                        sumGreen += copy[new_i][new_j].rgbtGreen;
                        sumBlue += copy[new_i][new_j].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtRed =  (BYTE)((sumRed / counter) + 0.5 );
            image[i][j].rgbtGreen = (BYTE)((sumGreen / counter)+ 0.5 );
            image[i][j].rgbtBlue = (BYTE)((sumBlue / counter) + 0.5);
        }
    }
}

