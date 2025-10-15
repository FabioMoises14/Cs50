#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hash;
    int espaco;
    int altura;
    //Solicitamos quando vai ser a Altura a ser ultilizada para o calculo, se altura for menor que 0 ou maior que 8, essa função vai ser repetida até está nesse intervalo
    do
    {
         altura= get_int("Qual a altura da sua escada?");
    }
    while(altura <= 0 || altura > 8 );
          //logo em seguida nos declaramos qual vai ser nosso "quadrado de operações" ou campo a ser trabalhado, e nesse campo vamo printar metade " " e a outra #
    for(int linha =0; linha <altura; linha++)
    {
        for( espaco = 0; espaco < altura - linha - 1; espaco++)
        {
          printf(" ");
        }
        for(hash = 0;hash <= linha; hash++)
        {
            printf("#");

        }
        printf("\n");
    }
}
