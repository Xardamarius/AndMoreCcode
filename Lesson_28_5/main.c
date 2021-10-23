#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *massiv = NULL;
    int cnt = 10;

    massiv = malloc( sizeof(*massiv) * cnt );

    for (int i = 0; i < cnt; i++)
    {
        if (i == 0)
            massive[i] = 1;
        else
            massiv[i] = massiv[i - 1] * 2;
    }

    cnt += 4;
    massiv = realloc( massiv, sizeof(*massiv) * cnt ;)

    for (int i = cnt - 4; i < cnt; i++)
        massiv[i] = 777;

    for (int i = 0; i < cnt; i++)
        printf("%d\n", massiv[i] );

    return 0;
}
