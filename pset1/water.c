#include <cs50.h>
#include <stdio.h>

int shower_convert(int shower_time);

int main(void)
{
    printf("Enter length of shower in minutes ");
    int shower_length = get_int();
    shower_convert(shower_length);
    printf("The equivalent amount in number of bottles is %i\n", shower_convert(shower_length));
}

int shower_convert(int shower_length)
{
    return shower_length * 1.5 * 128 / 16;
}