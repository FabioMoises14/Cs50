#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>



int main(void)
{
    string player[2];
    player[0] = get_string("Player1: \n");
    player[1] = get_string("Player2: \n");

    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3 , 10, 1, 1, 1, 1, 4, 4, 8, 4};

    int somatotal[2];
    somatotal[0] = 0;
    somatotal[1] = 0;

    for(int i = 0, p1 = strlen(player[0]); i < p1 ;i++)
    {
        char letra = tolower(player[0][i]);
        if(letra >= 'a' && letra <= 'z')
        {
            int K = letra - 'a';
            int pontuacao = points[K];
            somatotal[0] += pontuacao;

        }
    }
    printf("%d\n", somatotal[0]);


    for(int i = 0, p2 = strlen(player[1]); i < p2 ;i++)
    {
        char letra = tolower(player[1][i]);
        if(letra >= 'a' && letra <= 'z')
        {
            int K = letra - 'a';
            int pontuacao = points[K];
            somatotal[1] += pontuacao;

        }
    }
    printf("%d\n", somatotal[1]);


    if(somatotal[0] > somatotal[1])
    {
        printf("player1 ganhou!\n");

    }
    else if(somatotal[1] > somatotal[0])
    {
        printf("Player2 ganhou\n");

    }
    else
    {
        printf("Empate\n");

    }




}
