/*
Remember that ASCII is a standard for mapping characters to letters. Here are some sample ones:

A   B   C   D   E   F   G   H   I  ...
65  66  67  68  69  70  71  72  73  ...

a   b   c   d   e   f   g   h   i   ...
97  98  99  100 101 102 103 104 105 ...
*/

#include <stdio.h>

int main(void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", (char) i, i);
    }
}

/*
This would also work since %c will force C to return a char


int main(void)
{
    for (int i = 65; i < 65 + 26; i++)
    {
        printf("%c is %i\n", i, i);
    }
}
*/
