#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Prototype

bool validar_argumento(int argc);
bool validar_letra(string key, int len);
bool validar_comprimento(int len);
bool validar_repeticao(string key, int len);
string cryptograph(string key, string plaintext);

int main (int argc, string argv[])
{
    if( !validar_argumento(argc) ) //Chamo a função de Validação argumento
    {
        return 1;
    }

    string key = argv[1];
    int lenk = strlen(key);

    if(!validar_letra(key, lenk) || !validar_comprimento(lenk) || !validar_repeticao(key, lenk)) // Chamo as funções para validações, se pelo menos 1 for falsa, então vai dar erro.
    {
        return 1;
    }
    string plaintext = get_string("PlainText:"); // Pego meu plaintext

    printf("%s", cryptograph( key, plaintext)); // Chamo a função que encoda o Plaintext e printo o resultado



}

bool validar_argumento(int argc)
{
    if(argc != 2) // Se não houver 1 argumento, então retorna falso.
    {
        printf("Erro: Necessary a key");

        return false;
    }

        return true;
}

bool validar_letra(string key,int lenk)
{
    for(int i = 0;i < lenk; i++)
    if(!isalpha(key[i]))    //Verifica se há apenas letras, se houver outra coisa então retorna falso.
    {
        printf("Erro: Just Letters\n");

        return false;
    }

    return true;
}

bool validar_comprimento(int lenk)
{
    if(lenk != 26 ) // Verifica se há 26 letras, se não houver, então retorna falso.
    {
        printf("Erro: 26-character key required\n ");

        return false;
    }

    return true;
}

bool validar_repeticao(string key, int lenk)

{
    char repetition[26] = {0}; //Criar Array repetition para conseguir guardar o valor que foi ativado.

    for(int i = 0; i < lenk; i++)
    {
        char upkey= key[i]; //Tornar toda a chave em maiusculo para padronizar a verificação
        int carry = upkey - 'A'; //Key - 'A' vai resultar no carry que vai ser o indice do array repetition;

        if(repetition[carry] == 1)  // Se o indice do carry no array repetition houver 1, então essa key ja foi usada
        {
            printf("Erro: key must not contain repeated letters. \n");

            return false;
        }
        repetition[carry] = 1;  //  Incrementa 1 para salvar o valor do indice no array repetiton
    }
    return true;
}

string cryptograph(string key, string plaintext)
{
    char alfabeto[26] = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"); // Array alfabeto vai servir para conseguir ultilizar o mesmo indice de uma letra para o indice da key.
    int lenp = strlen(plaintext);
    int lena = strlen(alfabeto);
    string letra_substitu = malloc(lenp + 1); // Guarda um espaço na memoria referente a todos os caracteres do plaintext
    int position = 0;   //Indice da letra_substitu;


    for(int i = 0; i < lenp; i++) // Loop para o plainText
    {
        if(isupper(plaintext[i]))   //Se o valor do plaintext atual for maiuculo então...
        {
            for(int k = 0; k < lena;k ++)
            {
                if(alfabeto[k] == plaintext[i]) //Quando o indice do alfabeto, tiver o mesmo valor de plaintext então
                    letra_substitu[position] = key[k];// substitui o plaintext na mesma posição com key..
                    position++; //incrementa a posição do indice para o proximo.
                    break;  //Para de buscar
                }
            }
        }

        else if(islower(plaintext[i]))  //Se o valor do plaintext atual for minusculo então..
        {
            char lettup = toupper(plaintext[i]); // Transforma o valor do plaintext para minusculo, para padronizara operação
            for(int k = 0; k < lena;k++)
            {
                if(alfabeto[k] == lettup) //Quando o indice do alfabeto, tiver o mesmo valor de lettup então
                {
                    letra_substitu[position] = key[k] + 32;// substitui o plaintext na mesma posição com key, porém, vai somar com +32 que é o valor minusculo da chave.
                    position++; //incrementa a posição do indice para o proximo.
                    break; // para de buscar.
                }
            }
        }
        else    //Se for espaço, pontuação ou outro caractere
        {
            letra_substitu[position] = plaintext[i]; //Apenas repete o plaintext
            position++; //Incrementa a posição para o proximo.
        }

    }

    letra_substitu[position] = '\0';
    return letra_substitu;
}
