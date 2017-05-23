#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    if(argc<=1)
    {
        printf("Usage: ./vigenere k\n");
        exit(1);
    }
    
    if(argc>2)
    {
        printf("Usage: ./vigenere k\n");
        exit(1);
    }
    
    // convert command line input from string to int varible keyword
    string keyword = argv[1];
    
    // check if keyword only contains alphabet characters
    for (int i = 0;  i < strlen(keyword); i++) 
    {
        if ((int)keyword[i] >= 0 && (int)keyword[i] < 65) 
        {
            printf("Use alphabetic characters");
            exit(1); 
        }
        else if ((int)keyword[i] > 91 && (int)keyword[i] < 97)
        {
            printf("Use alphabetic characters");
            exit(1);
        }
        else if ((int)keyword[i] > 127)
        {
            printf("Use alphabetic characters");
            exit(1);    
        }
    } 
    
    //prompt user input and initialized
    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: ");
    
    //create lower_case_array
    char lower_case[26] = "abcdefghijklmnopqrstuvwxyz";
    
    //create upper_case_array
    char upper_case[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
    
    //convert key from string to int[]
    int array_length =strlen(plaintext); 
    int key_number[array_length]; // [array_length]
    int key_length = strlen(keyword);
    //loop though key_number for the length of plaintext
    for (int i = 0;  i < (strlen(plaintext)); i++)
    {
        //if char is uppercase
        if (keyword[i % key_length] >= 65 && keyword[i % key_length] < 91 )
        {
            key_number[i] = (keyword[i % key_length]) - 65;   
        }
        // if char is lowercase
        else if (keyword[i % key_length] >= 97 && keyword[i % key_length] < 123)  
        {
            key_number[i] = (keyword[i % key_length]) - 97;  
        }
    }
    
    //print out letters accoring to ceasar cryptography
    int j = 0;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] < 91 )
        {
            printf("%c",  upper_case[((plaintext[i] - 65 + key_number[j]) % 26)]);
            j++;
        }
        //branch if letter is lower case
        else if (plaintext[i] >= 97 && plaintext[i] < 123)
        {
            printf("%c", lower_case[((plaintext[i] - 97 + key_number[j]) % 26)]);
            j++;
        }
        //branch if any other character
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
}