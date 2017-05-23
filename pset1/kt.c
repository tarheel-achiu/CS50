#include <cs50.h>
#include <stdio.h>

int get_digit ();

long long test;

int main(void)
{
    test = get_digit();
    char buffer[10];
    snprintf(buffer, 10, "%lld", test);
    

}

int get_digit ()
{
    long long cc_number = 1234567890123456;
    //long long digit = 3;
    
    return(cc_number);
    //return (cc_number / (10 * digit)) % 10;
    printf("cc_number");
    printf("digit");
}