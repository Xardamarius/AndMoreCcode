 #include <stdio.h>
#include <stdlib.h>

int main()
{
    char *mas = NULL;
    int cnt = 4;

    mas = malloc( sizeof(char) * cnt );

    for (int i = 0; i<cnt; i++)
        mas[i] = 123;

    for (int i = 0; i<cnt; i++)
        printf("%d\n", mas+i );

    free(mas);
    mas = NULL;

    return 0;
}
