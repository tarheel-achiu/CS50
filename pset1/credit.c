#include <cs50.h>
#include <stdio.h>
#include <math.h>

int luhns_algorithm(long long n);
int card_type(long long n);

//initialize variables
long long cc_number = 0;
int counter = 0;


int main(void)
{
    //store user input
    do 
    {
    printf("Number: ");
    cc_number = get_long_long();
    }
    while (cc_number == 0);
    
    // call function to validate cc number length, if correct continue the validation, if wrong return INVALID
    if  (valid_digit_length(cc_number) == 1)
    {
      
        //converting long long to backwards order array 
        int temp_cc_array[counter];
        int n2convert = cc_number;
        for (int i = 0; i < counter; i++)
        {
            
            temp_cc_array[i] = n2convert % 10;
            n2convert = n2convert / 10;
        }
        
       //flipping the array to the original order
       int final_cc_array[counter];
       
       for (int i = 1; i < counter; i++)
       {
           final_cc_array[i] = temp_cc_array[i];
       }
  
        
        
        //passing cc_array to a function that validates using luhns algorithm. If passes continue to determine card type, if failed return INVALID
        if luhns_algorithm(cc_array) == 1
        {
            //Determining card type accorind to cc numbers buckets assignments and returning value, if not able to determine return INVALID
            if card_type(cc_array) == 1
            {
                printf("AMEX\n");  
            }
            else if card_type(cc_array) == 2
            {
                printf("MASTERCARD\n"); 
            }
            else if card_type(cc_array) == 3
            {
                printf("VISA\n");     
            }  
            else
            {
                printf("INVALID");
            }
        else
        {
            printf("INVALID");
        }
        }
        
        
        
    }
    else 
    {
        printf("INVALID");
    }
    return 0;
 
}

int valid_digit_length (long long digits)
{
    while (digits > 0)
    {
        digits = digits/10;
        counter++; 
    }
    if ((counter != 13) && (counter != 15) && (counter != 16))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


int luhns_algorithm(int param[])
{
    
    long long every_other_sum1;
    long long every_other_sum2;
    
    for (long long i = 1; i < n; i += 2)
    {
        every_other_sum1 = every_other_sum1 + final_cc_array[i] * 2;
        
    }
    
    for(long long j = 1; j < n; j += 2)
    {
        every_other_sum2 = every_other_sum2 + final_cc_array[j];
    }
    
    if ((every_other_sum1 + every_other_sum2)  % 10 == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int card_type(int cc_array[])
{
    if (final_cc_array[0] == 3 && final_cc_array[1] == 4) || (final_cc_array[0] == 3 && final_cc_array[1] == 7)
    {
        return 1; //AMEX
    }
   
    if (final_cc_array[0] == 5 && final_cc_array[1] == 1) || (final_cc_array[0] == 5 && final_cc_array[1] == 2) || (final_cc_array[0] == 5 && final_cc_array[1] == 3) || (final_cc_array[0] == 5 && final_cc_array[1] == 4) || (final_cc_array[0] == 5 && final_cc_array[1] == 5)
    {
        return 2; //MASTERCARD
    }
    
    if (final_cc_array[0] == 4)
    {
        return 3; //VISA
    }
    else
    {
        return 0;
    }
}

