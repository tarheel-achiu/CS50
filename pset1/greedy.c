#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
   // prompt user input and store value
   
   float amount_owed = 0;
   do
   {
       printf("O hai! How much change is owed?\n");
       amount_owed = get_float();
   }
   while (amount_owed <= 0);
   
   // round the cents
   int cents_owed = (int) round(amount_owed * 100);
    
    // calculated minimum amount of coins to be returned
    int tracker = cents_owed;
    int num_coins = 0;
    
    while (tracker > 0)
    {
        if (tracker >= 25)
        {
            num_coins++;
            tracker = tracker - 25;
        }
        else if (tracker >= 10)
        {
            num_coins++;
            tracker = tracker - 10;
        }
        else if (tracker >= 5)
        {
            num_coins++;
            tracker = tracker - 5;
        }
        else
        {
            num_coins++;
            tracker = tracker - 1;
        }
      
    }
   

    printf("%i\n", num_coins);
}