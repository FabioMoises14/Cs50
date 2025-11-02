#include<cs50.h>
#include<stdio.h>

int get_piramide_row(void);
void print_spaces(int spaces);
void print_hashes(int hashes);
void print_piramide_row(int spaces, int hashes);
void print_piramide(int height);




int main(void)
{
    int height = get_piramide_row();
    print_piramide(height);

}

int get_piramide_row (void)
{

    int height = get_int("Qual a altura da sua piramide?");

    return height;
}
void print_spaces(int spaces)
{
    for(int a = 0; a < spaces; a++)
    {
        printf(" ");
    }
}
void print_hashes(int hashes)
{
    for(int a = 0; a < hashes; a++)
    {
        printf("#");
    }
}

void print_piramide_row(int spaces, int hashes)
{
    print_spaces(spaces);
    print_hashes(hashes);
    printf("  ");
    print_hashes(hashes);
    printf("\n");


}

void print_piramide(int height)
{
    for(int row = 1; row <= height;row++)
    {
        int hashes = row;
        int spaces = height - row ;

         print_piramide_row(spaces,hashes);
    }

}
