#include <cs50.h>
#include <stdio.h>

int build_pyramid(int n);

int main(void)
{
   
   //Declare and intialize variables
   int pyramid_height = 0;
   
   //Receive user input, validate data before proceeding
   do
   {
        printf("Height: ");
        pyramid_height = get_int();
        if (pyramid_height == 0)
        {
            return 0;
        }
   }
   while (pyramid_height < 1 || pyramid_height > 23);
   
   build_pyramid (pyramid_height);


}

int build_pyramid(int n)
{ // loop for line counter
    for (int i = 0; i < n; i++)
    { // loop for spaces
        for (int j = n - i - 1; j > 0; j--)
        {
            printf(" ");
        } 
        // loop for #s
        for(int k = 0; k < (i + 1); k++)
            {
                printf("#");
            }
                // loop for middle space
            {
                printf("  ");
            }
        // loop for right pyramid
        for (int k = 0; k < (i + 1); k++)
            {
                printf("#");    
            }
        printf("\n");
    }
    return 0;
}