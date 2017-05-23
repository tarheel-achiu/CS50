#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{   
    printf("enter string: ");
    char *s = get_string();
    if (s == NULL)
    {
        return 1;
    }
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // by adding +1 to the pointer s, you are iterating the next char in the string
        // same as iteration through an array and printing like this: printf("%c\n", s[i])
        printf("%c\n", *(s+i));
    }
}