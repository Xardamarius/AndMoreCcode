#include <stdio.h>
#include <stdlib.h>

int Inc(int a)
{
    return a + 1;
}

void Inc2(int *x)
{
    if(x != NULL)
        *x = *x + 1;
}

int main()
{
    int i = 7;
    i = Inc(i);
    Inc2(NULL);
    printf("%d\n", i);
    return 0;
}
