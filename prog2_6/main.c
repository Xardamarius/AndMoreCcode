#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    do
    {
        printf("input integer = ");
        scanf("%d", &a);
    }
    while(a != 7);

    return 0;
}
