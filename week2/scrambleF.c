#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>


string player[2];
const int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3 , 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calculo(string jogador);

int main(void)
{
//Pegar a palavra
    player[0] = get_string("Player 1: \n");
    player[1] = get_string("Player 2: \n");
//Ponto vai ser igual ao retorno da função calculo e a função calculo tem o parametro jogador na função calculo, e na função main é substituido pelo jogador 1 e 2.
    int ponto1 = calculo(player[0]);
    int ponto2 = calculo(player[1]);

//Condicionais

    //Se os pontos forem iguais a -1 que é o return de erro. então está errado.
    if(ponto1 == -1 && ponto2 == -1)
    {
        printf("Apenas uma palavra por vez, por favor");
        return 2;
    }
    //condicionais para verificar quem venceu
    if(ponto1 > ponto2 )
    {
        printf("Jogador 1 ganhou\n");
    }
    else if(ponto2 > ponto1)
    {
        printf("Jogador 2 ganhou\n");
    }
    else
    {
        printf("Empate\n");
    }
}

<<<<<<< HEAD

=======
>>>>>>> 851a57220f55b568fcb0951fadd8ffedd36db314
//Calculo para UM JOGADOR
int calculo(string jogador)
{
    int somatotal = 0;
    //Loop para vertificar uma letra de cada vez
    for(int i = 0, p = strlen(jogador); i < p ; i++)
    {
        //Se houver espaço quer dizer que são mais de 1 palavra, retornar -1 = erro.
        if(jogador[i] == ' ')
        {
            return -1;
        }
        //Deixar todas letras em minusculo, para realizar o calculo
        char letra = tolower(jogador[i]);
        //Verificar se o input é uma letra valida
        if (letra >= 'a' && letra <= 'z')
        {
                //letra - a = a - a = Indice do array.
            somatotal += letra - 'a';
        }
    }
    // Retornar Valor da função
    return somatotal;
}

