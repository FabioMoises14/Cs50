#include<cs50.h>
#include<stdio.h>



int main(void)
{
    long numero;
    int soma_total = 0;
    int contador = 0;
    do
    {
        numero = get_long("Diga o número do seu cartão:");
    }
    while(numero < 100000000000000 || numero > 999999999999999 )

    while (numero > 0)
    {
        int digito = numero % 10;

    if ( contador % 2 == 1)
    {
        digito = digito * 2;

        if(digito >= 10)
        {
         soma_total += (digito /10) + (digito % 10);
        }
        else
        {
            soma_total += digito;
        }
    }

    else
    {
        soma_total += digito;
    }


    numero = numero / 10;
    contador++;
    }
    if(soma_total % 10 == 0)
    {
       printf("Este número é válido!\n");
    }
    else
    {
       printf("esse cartão é invalido otario, pega um real\n");
    }
}
