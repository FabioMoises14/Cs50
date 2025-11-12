#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


//prototipo
bool only_digits (string s);
string rotate(string texto, int key);

//Argc e Argv para pegar argumentos
int main(int argc, string argv[])
{
//Permitir apenas 2 command line
    if(argc != 2)
    {
        printf("Necessário pelo menos um command line argument");
        return -1;
    }

//Chamar a função para verificar se é um digito
    if(!only_digits(argv[1]))
    {
         printf("Digite apenas uma chave");
        return -2;
    }
//Tranformar o argumento que era uma string em uma variavel de valor inteiro chamada key
   int key = atoi(argv[1]);
//Pegar o texto que iremos criptografar
    string texto = get_string("Plaintext:");
//Chamar função Rotate que tem o texto encriptografado
    string encipher = rotate(texto, key);

    printf("%s", encipher);//Printar o texto incriptografado
}



//Fução para verificar a key é um número
bool only_digits (string s)
{
    for(int i = 0,len = strlen(s);i < len; i++)
    {
        if(!isdigit((s[i])))//Se o número não for um digito retorna falso
        {
            return false;
        }
    }

    return true; // Se sim, verdadeiro
}

//Função para Encriptografar o Texto
string rotate(string texto, int key)
{
    for(int i = 0, len = strlen(texto); i < len; i++)
    {
        if(isalpha(texto[i]))   //Se for uma letra então continuamos
        {
            if( texto[i] <= 90) //Se o caractere for menor que 90 então é Maiusculo, após vai seguir a operação com valor maiusculo
            {
                texto[i] = (texto[i] - 'A' + key) % 26 + 'A'; // Exemplo: B - A = | 1 + 2 | = | 3 % 26 | = | 3 + 'A'| = D;
            }
            else // Se não for menor que 90 ent é maior, nesse caso faz a operação com minusculo
            {
                 texto[i]= (texto[i] - 'a' + key) % 26 +'a';
            }
//OBS : Esses calculos servem para mudar o valor do proprio texto.
        }
    }

    return texto; // Retornar texto
    }
