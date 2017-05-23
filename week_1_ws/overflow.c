#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 1;
    for (int i = 0; i < 64; i++)
    {
        printf("n is %i\n", n);
        n = n * 2;
    }
}

/* A way to fix this is to use long long data type
int main(void)
{
    long long n = 1;
    for (int i = 0; i < 64; i++)
    {
        printf("n is %ld\n", n);
        n = n * 2;
    }
}
*/
