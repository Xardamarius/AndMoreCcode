#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 22, b = 8;
    a += ++b + ++b;
    printf("%d %d ", a, b);
    return 0;
}
