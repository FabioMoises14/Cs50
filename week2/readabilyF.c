#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
//Protoype para monstrar quias vao ser as funções utilizadas
int count_letters(string texto);
int count_words(string texto);
int count_setences(string texto);
float calculo(int letters, int words, int setences);

int main(void)
{
//Pegar texto que vai ser ultilizado
    string texto = get_string("Texto: ");
//Puxar o retorno das funções
    int letters = count_letters(texto);
    int words = count_words(texto);
    int setences = count_setences(texto);
    float index = calculo(letters , words, setences);

    int grade = round(index); //Crio outra variavel para arrendondar o Index que vai estar float.

    printf("%d\n", letters);
    printf("%d\n", words);
    printf("%d\n", setences);
//Condicionais
    if(grade < 1)
    {
        printf("Before Grade 1\n");

    }
    else if(grade >= 16)
    {
        printf("After Grade 16\n");

    }
    else
    {
        printf("Grade %d\n", grade);
    }

}


//Função para contar o número de letras
int count_letters(string texto)
{
    int letters = 0;//iguala a zero pq vai somar
    for(int i = 0, comprimentot = strlen(texto);i < comprimentot; i++)
    {

        if(isalpha(texto[i]))//Verificar se é uma letra, se sim, aumenta o contador letter para 1.
        {
        letters += 1;
        }
    }
    return letters;
}

//Função para contar o número de palavras
int count_words(string texto)
{
    int words = 1;//Iguala a 1, porque todo começo de texto há 1 palavra.
    for(int i = 0, comprimentot = strlen(texto); i < comprimentot; i++)
    {
        if(texto[i] == 32 )//Se houver algum espaço, aumenta contador words em 1.
        {
            words += 1;
        }
    }
    return words;
}

//Função para contar o número de sentenças
int count_setences(string texto)
{
    int setences = 0;// Iguala a zero
    for(int i = 0, comprimentot = strlen(texto); i < comprimentot; i++)
    {
        if(texto[i] == '?' || texto[i] == '.' || texto[i] =='!' ) // Verifica se houver '?' ',' '.' '!', então significa que acabou uma sentença
        {
            setences += 1;  //E então aumenta contador setence em 1.
        }
    }
    return setences;
}

//Calculo
float calculo(int letters, int words, int setences) // Vai ultilizar como o parametro todas as ultimas funções
{
    float L = 0; //Iguala a zero, pq irá fazer operações
    float S = 0;
    float index = 0;

    L = ((float)letters / (float)words) * 100; // Transformar os valores que eram int para Float, para conseguir fazer o calculo sem intrucamento
    S = ((float)setences / (float)words) * 100;

    index = 0.0588 * L - 0.296 * S - 15.8;

    return index;

}