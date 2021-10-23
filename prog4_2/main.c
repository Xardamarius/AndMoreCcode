#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[21];
    s[20] = '\0';

    for (int i=0; i<20; i++)
        s[i] = rand() % ('z'-'a'+1) + 'a';

    printf("%d", s);

    return 0;
}
