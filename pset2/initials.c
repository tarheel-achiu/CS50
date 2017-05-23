#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
   // store user input in variable user_name 
   // asume that it will only contain letters and spaces
   //printf("Enter your name: ");
   string user_name = get_string();
   
   //declare num_initials variable
   int num_initials = 0;

   // iterate though the string and pull first letter of each word
   for (int i = 0; i < strlen(user_name); i++)
   {
      if (i == 0 && user_name[i] != ' ')
      {
         printf("%c", toupper(user_name[i]));
         num_initials++;
      }
      else if (user_name[i] != ' ' && user_name[i - 1] == ' ')
      {
         printf("%c", toupper(user_name[i]));
         num_initials++;
      }
   }
   printf("\n");
}  