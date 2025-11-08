#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main(void)
{
    string texto = get_string("Diga seu texto: ");

//prototype
    int words = 1;
    int setences = 1;
    int letters = 0;
    float index = 0;
    int L = 0;
    int S = 0;
//FUNÇÃO PARA PASSAR POR TODO O TEXTO
    for(int i = 0,t = strlen(texto)  ; i < t; i++ )
    {
//COUNT LETRAS
         if(texto[i] != 32)
        {
            letters += 1;
        }
//COUNT PALAVRAS
        if(texto[i] == 32)
        {
            words += 1;
        }
//COUNT SETENÇAS
        if(texto[i] == 63|| texto[i] == 46 || texto[i] == 33 || texto[i] == 44)
        {
            setences += 1;
        }
    }
//CALCULO
    L = (letters / words) * 100;
    S = (setences / words) * 100;

     index = 0.0588 * L - 0.296 * S - 15.8;
     index = roundf(index);
//CONDICIONAIS
    if(index < 1)
    {
        printf("Before Grade 1\n")
        return 1;
    }
    if(index > 16)
    {
        printf("After Grade 16\n")
        return 2;
    }

    printf("Este testo é de grade %.0f\n", index);
//printf("%d\n",letters);
//printf("%d \n",words);
//printf("%d\n",setences);

}

