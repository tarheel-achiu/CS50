#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <cs50.h>

int main()
{
    // a will hold the number
    printf("Enter number to convert into an array: ");
    uint64_t a =  get_long_long();

    // first we need to see the length of the number a
    int num_digits = 0;
    uint64_t b = a;
    while( b>=10 )
    {
        b=b/10;
        num_digits++;
    }
    short digits[20]= {0};
    for( int i = num_digits; i >= 0; i-- )
    {
        digits[i]=a%10;
        a=a/10;
    }

    for( int i = 0; i <= num_digits; i++ )
    {
        printf("the value of index %i is \"%d\"\n", i, digits[i]);
    }
}


/*
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <cs50.h>

int main()
{
    // a will hold the number
    printf("Enter number to convert into an array: ");
    string input = "";
    uint64_t a;
    //take user input
    fgets(input,20,stdin);
    sscanf(input, "%"SCNd64);
    //scanf("%"PRId64, &a);
    // first we need to see the length of the number a
    int num_digits = 0;
    uint64_t b = a;
    while( b>=10 )
    {
        b=b/10;
        num_digits++;
    }
    short digits[20]= {0};
    for( int i = num_digits; i >= 0; i-- )
    {
        digits[i]=a%10;
        a=a/10;
    }

    for( int i = 0; i <= num_digits; i++ )
    {
        printf("the value of index %i is \"%d\"\n", i, digits[i]);
    }
}
*/



/*
Second attempt with int64, issues when b == 0, so ned try is using uint64

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <cs50.h>

int main()
{
    // a will hold the number
    printf("Enter number to convert into an array: ");
    int64_t a = get_long_long();
    // first we need to see the length of the number a
    int num_digits = 0;
    int64_t b = a;

    while( b>0 )
    {
        b=b/10;
        num_digits++;
    }
    int64_t digits[20]= {0};
    for( int i = num_digits; i >= 0; i-- )
    {
        digits[i]=a%10;
        a=a/10;
    }

   while( b>=0 )
    {
        b=b/10;
        num_digits++;
    }
    int64_t digits[20]= {0};
    for( int i = num_digits; i >= 0; i-- )
    {
        digits[i]=a%10;
        a=a/10;
    }
    for( int i = 0; i <= num_digits; i++ ) {
    printf("the value of digit %i is \"%"PRId64"\"\n", i, digits[i] );
    }

    printf("the value of test1 is \"%"PRId64"\"\n", digits[1] * 2);

    int64_t test = digits[1]* 2;

    printf("the value of test1 is \"%"PRId64"\"\n", test);

}
*/


/*
First attempt

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // a will hold the number
    unsigned long long int a = 123456;

    // str will hold the result which is the array
    unsigned long long int str[23] = {0};
    // first we need to see the length of the number a
    long long int b = a;
    // count is determining the number of digits
    size_t num_digits = 0;
    while(b>0)
    {
        b = b / 10;
        num_digits++;
    }
    // the length of the number a will be stored in variable i
    // the while loop below will store the digit from the end of str to the
    // the beginning
    for (int i = 0, n = strlen(s); i < n; i++)
    {

    }

    while(i>0)
    {
        str[i - 1]= a % 10;
        a = a / 10;
        i--;
    }
    // only for test
    printf("the value of str is \"%llu\"\n", str[1]); //[0]

    printf("the value of str is \"%llu\"\n", str[1] * 2);

    unsigned long long test = str[1]* 2;

    printf("the value of test is \"%llu\"\n", test);


    return 0;
}
*/
