#include <stdio.h>
#include <stdlib.h>

void DoSomething(int *x, int *y)
{
    ++*x;
    *y *= *y;
}

int main()
{
    int a = 5;
    int b = 9;
    DoSomething(&a, &b);
    printf("%d\n%d\n", a, b);
    return 0;
}
