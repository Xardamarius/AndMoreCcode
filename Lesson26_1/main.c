#include <stdio.h>
#include <stdlib.h>

void CreateInt(int **p)
{
    *p = malloc( sizeof(int) );
}

int main()
{
    int *a = NULL;

    CreateInt(&a);

    if (a != NULL)
    {
        *a = 777;
        printf("%d\n", *a);
    }

    free(a);
    a = NULL;

    return 0;
}
