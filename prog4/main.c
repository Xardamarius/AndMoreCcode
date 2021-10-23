#include <stdio.h>
#include <stdlib.h>

#define k 10

int main()
{
    int mas [k];
    for(int i=0; i<k; i++)
        mas[i] = rand() % 20 + 20;

    for(int i=0; i<k; i++)
        printf("%d\n", mas[i]);

    int r = rand() % 10 + 10;

    return 0;
}
