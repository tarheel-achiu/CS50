#include <cs50.h>
#include <stdio.h>

/* || means OR. && means AND*/

int main(void)
{
    char c = get_char();
    if (c == 'y' || c == 'Y')
    {
        printf("yes\n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf("no\n");
    }
}
