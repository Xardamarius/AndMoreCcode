#include <stdio.h>
#include <stdlib.h>

void CreateInt(int **p)
{
    *p = malloc( sizeof(int) );
}

void FreeAndNil(void **p)
{
    free(*p);
    *p = NULL;
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

    FreeAndNil(&a);

    if (a == NULL)
        printf("OK\n");

    return 0;
}
