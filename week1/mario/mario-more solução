
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hash;
    int espaco;
    int altura;
    do
    {
     altura = get_int("Qual a altura da sua escada?");
    }
    while (altura <= 0 || altura > 8 );

    for (int linha =0; linha <altura; linha++)
    {

        for ( espaco = 0; espaco < altura - linha - 1; espaco++)
        {
            printf(" ");
        }

        for (hash = 0; hash <= linha; hash++)
        {
            printf("#");
        }

        for(int buraco = 1; buraco <= 2; buraco ++)
        {
            printf(" ");
        }

              for(hash = 0; hash <= linha; hash++)
        {
            printf("#");
        }

        for(espaco = 0; espaco < altura - linha - 1; espaco++)
        {
            printf(" ");
        }

        printf("\n");
    }

}
