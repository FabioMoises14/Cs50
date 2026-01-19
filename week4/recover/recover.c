#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK 512


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage:./recover image \n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if(card = NULL)
    {
        printf("Could not open file.\n")   //CASO ERRO
    }
    FILE *jpg = NULL;
    uint8_t buffer[BLOCK];
    int counter = 1;
    char filename[8];
    while(fread(buffer, 1, BLOCK, card ))
    {

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3]&0xf0) == 0xe0)
        {
                             //VERIFICA SE É UM HEADER, SE SIM ENTÃO CRIA UM ARQUIVO E FECHA O ULTIMO

            if(jpg != NULL) //SE HOUVER ALGUM JPG ABERTO FECHA
            {
                fclose(jpg);
            }
                sprintf(filename,"%03i.jpg", counter);  //CRIA NOME DO NOVO ARQUIVO COM O COUNTER
                jpg = fopen(filename,"w");              //ABRE ARQUIVO E ESCREVE NELE

            if (jpg == NULL)
            {
                    printf("Could not create %s\n", filename);  //CASO ERRO
                    return 1;
            }
                counter++;
        }

                            //NÃO É UM HEADER, ENTÃO APENAS ESCREVE O CONTEUDO DO BLOCK NO ARQUIVO JPG ATUAL
        if(jpg != NULL)
        {
            fwrite(buffer, 1, BLOCK, jpg);
        }
    }
    
    if(jpg != NULL)
    {
        fclose(jpg);
    }
    fclose(card);
}

