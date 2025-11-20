#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//Pegar a chave, a chave vai ser argumento
int main(int argc, string argv[])
{

    string key = argv[1];
    int len = strlen(key);
    char alfabeto[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int repetion[26] = {0};


//Verificar se há apenas uma chave.
    if(argc != 2)
    {
        printf("Erro: Necessary a key.\n");
        return -1;
    }

    for(int i = 0; i < len; i++) //Loop por todo a chave
//Verifica se há 26 Letras
    {   if(len != 26)
        {
            printf("Erro: Necessary 26 letter to the key. \n");
            return -3;
        }
//Verifica se são letras
        if(!isalpha(key[i]))
        {
            printf("Erro: Apenas letras. \n");
            return -2;

        }
//Verificar se foi repetido.

       char upletter = toupper(key[i]);
       int carryr = upletter - 'A';

       if(repetion[carryr] == 1)
       {
        printf("Erro: A letra não pode ser repetida. \n");
        return -6;
       }


       repetion[carryr] = 1;
    }
    //Pegar o Plain text

    string plaintext = get_string("PlainText:");

    //Encriptar
//Primeiro printa o encriptado que for maiusculo



for(int i = 0, lenp = strlen(plaintext); i <lenp; i++ ) //Loop para os indices do Plaintext
{
    if(isupper(plaintext[i]))  //Vai printar o plaintext se for upper
    {
        for(int k = 0, lena = strlen(alfabeto); k < lena; k++  ) // Loop para o indice da String Alfabeto
        {
            if(alfabeto[k] == plaintext[i])// Verifico se o valor que está na posição do loop da string, for igual a plaintext, eu subsitituo o valor e imprimo.
            {
                char letra_subs = key[k];
                printf("%c", letra_subs);
            }
        }
    }
    else if(islower(plaintext[i]))
    {
        char letmin = toupper(plaintext[i]);  //Transforma em Upper para conseguir se relacionar com a Key que é maiuscula
        for(int k = 0, lena = strlen(alfabeto); k < lena; k++ )
        {
            if(alfabeto[k] == letmin)   // Se o indice do alfabeto em K for igual ao plain text então pode substituir
            {
                char letra_subs = key[k]; //Seta uma variavel que vai ser igual a key chave, ou seja, dentro do indice K do alfabeto, também vai ser puxada a cahve no indice K, ou seja mesma posição do arraz
                printf("%c", tolower(letra_subs);

            }


        }

    }
}
}


