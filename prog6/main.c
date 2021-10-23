#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 5;
    int *iPtr = NULL;
    iPtr = &i;

    if (iPtr != NULL)
    {
        *iPtr = 7;
        printf("%d\n", *iPtr);
    }


    return 0;
}
