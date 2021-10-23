#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *p = NULL;
    p = malloc( 8 );

    if (p != NULL)
    {
        *(double *)p = 7.2;
        printf("%f\n", *(double *)p );
    }

    free(p);
    p = NULL;

    return 0;
}
