#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    if(argc<=1)
    {
        printf("Usage: ./caesar k");
        exit(1);
    }
    // convert command line input from string to int varible k
    int k = atoi(argv[1]);
    
    //prompt user input and initialized
    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: ");
    
    //create lower_case_array
    char lower_case[26] = "abcdefghijklmnopqrstuvwxyz";
    
    //create upper_case_array
    char upper_case[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    //print out letters accoring to ceasar cryptography
    for (int i = 0;  i < strlen(plaintext); i++)
    {
        //branch if letter is upper case
        if (plaintext[i] >= 65 && plaintext[i] < 91 )
        {
            printf("%c",  upper_case[((plaintext[i] - 65 + k) % 26)]);    
        }
        //branch if letter is lower case
        else if (plaintext[i] >= 97 && plaintext[i] < 123)
        {
            printf("%c", lower_case[((plaintext[i] - 97 + k) % 26)]);
        }
        //branch if any other character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}