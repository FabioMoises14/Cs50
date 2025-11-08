#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>



int main(void)
{
//Pegar a palavra dos Players
    string player[2];
    player[0] = get_string("Player1: \n");
    player[1] = get_string("Player2: \n");

//Quantidade de ponto organizado pelo alfabeto
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3 , 10, 1, 1, 1, 1, 4, 4, 8, 4};

//soma da quantidade de ponto
    int somatotal[2];
    somatotal[0] = 0;
    somatotal[1] = 0;


//Ler a quantidade de pontos do player 1, linha por linha
    for(int i = 0, p1 = strlen(player[0]); i < p1 ;i++)
    {
//Verifica se houver mais de uma palavra, não vai dar certo
        if(player[0][i] == ' ')
        {
            printf("Apenas uma palavra por vez");
            return -1;
        }
//transforma todas as letras em minusculas e verifica se são todas letras
        char letra = tolower(player[0][i]);
        if(letra >= 'a' && letra <= 'z')
        {
// letra - a = pontuação no indice points a - a = indice[0];
            int K = letra - 'a';
            int pontuacao = points[K];
            somatotal[0] += pontuacao;
        }
    }
//mostrar a soma total do player 1
    printf("%d\n", somatotal[0]);


//Player dois é uma "copia" do player 1
    for(int i = 0, p2 = strlen(player[1]); i < p2 ;i++)
    {
        if(player[1][i] == ' ')
        {
            printf("Apenas uma palavra por vez");
            return -1;
        }

        char letra = tolower(player[1][i]);

        if(letra >= 'a' && letra <= 'z')
        {
            int K = letra - 'a';
            int pontuacao = points[K];
            somatotal[1] += pontuacao;
        }
    }
    printf("%d\n", somatotal[1]);


//Mostar qual do dois tirou mais pontos
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
