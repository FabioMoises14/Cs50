#include "helpers.h"

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
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int Gx[3][3] = {
    {-1, 0 , 1},
    {-2, 0, 2},
    {-1, 0, 1}
    };

    int Gy[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
    };

    for(int i = 0;i < height; i++)
    {
        for(int j = 0;j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {                                                       //I E J SE REFEREM A IMAGEM COMPLETA, ONDE CADA INDICE É UM PIXEL
        for(int j = 0; j < width; j++)
        {
            float GxRed = 0;float GyRed = 0;
            float GxGreen = 0;float GyGreen = 0;
            float GxBlue = 0; float GyBlue = 0;

            for(int di = -1; di <= 1; di++)                     //DELTAS SÃO O 3X3 DE CADA PIXEL
            {
                for(int dj = -1; dj <=1;dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;

                    if(new_i >= 0 && new_i < height && new_j >=0 && new_j < width)
                    {
                        GxRed += Gx[di+1][dj+1] * copy[new_i][new_j].rgbtRed;
                        GyRed += Gy[di+1][dj+1] * copy[new_i][new_j].rgbtRed;

                        GxGreen += Gx[di+1][dj+1] * copy[new_i][new_j].rgbtGreen;
                        GyGreen += Gy[di+1][dj+1] * copy[new_i][new_j].rgbtGreen;

                        GxBlue += Gx[di+1][dj+1] * copy[new_i][new_j].rgbtBlue;
                        GyBlue += Gy[di+1][dj+1] * copy[new_i][new_j].rgbtBlue;


                    }
                }
            }

            int pixelRed  = round(sqrt(GxRed*GxRed + GyRed * GyRed));
            int pixelGreen= round(sqrt(GxGreen*GxGreen + GyGreen * GyGreen));
            int pixelBlue = round(sqrt(GxBlue*GxBlue + GyBlue * GyBlue));

            if(pixelRed > 255){pixelRed = 255;}
            if(pixelGreen > 255){pixelGreen = 255;}
            if(pixelBlue > 255){pixelBlue = 255;}

            image[i][j].rgbtRed   = pixelRed ;
            image[i][j].rgbtGreen = pixelGreen;
            image[i][j].rgbtBlue  = pixelBlue;
        }
    }

    return;
}
