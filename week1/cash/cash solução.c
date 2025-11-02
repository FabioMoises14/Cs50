#include<cs50.h>
#include<stdio.h>


int main(void)
{
    int cash = get_int("Change owed: ");
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;
    while(cash >0)
         if(cash >= 25)
         {
            cash -= 25;
            quarter++;

         }
        else if(cash <= 10)
         {
            cash -= 10;
            dime++;

          }
        else if(cash <=5)
         {
        cash -= 5;
        nickel++;

        }
        else;
        {
        cash--;
        penny++;
        }
      printf("You use\n %d quarter\n %d penny\n %d dime\n %d nickel\n", quarter,  penny,  dime,  nickel);

}

