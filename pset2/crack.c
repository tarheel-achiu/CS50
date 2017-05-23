#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    if(argc<=1)
    {
        printf("Usage: ./crack hash");
        exit(1);
    }
    //create attempted hash
    string cracked_hash = '';
    
    //brute force
    //generate every possible password up to 4 char in lenth
    //loop though and guess each char
    do
    {
        string password = '';
        for (int char_index = 0;  char_index < 4; char_index++)
        {
            //loop though each version of salt
            for (int i = 65;  i < 127; i++)
            {
                
            }
        }
    } while (cracked_hash !=  argv[1]);
    
    
    
}