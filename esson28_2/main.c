#include <stdio.h>
#include <stdlib.h>

void DoSomething(int *x, int *y)
{
    *x += *y;           //  x = 5 + 9 = 14
    *y = *x - *y;       //  y = 14 - 9 = 5
    *x = *x - *y;       //  x = 14 - 5 = 9
}

int main()
{
    int a = 5;
    int b = 9;
    DoSomething(&a, &b);
    printf("%d\n%d\n", a, b);
    return 0;
}
