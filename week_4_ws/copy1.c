#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    
    printf("s: ");
    char *s = get_string();
    if (s == NULL)
    {
        return 1;
    }

// mallocs parameter is the number of bytes you want to allocate to the variable    
    char *t = malloc((strlen(s) + 1) * sizeof(char));
    if (t == NULL)
    {
        return 1;
    }
// iterate all the way though the string to the /0    
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }
    
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    
    printf("s: %s\n", s);
    printf("t: %s\n", t);

//free()     
    free(t);
}