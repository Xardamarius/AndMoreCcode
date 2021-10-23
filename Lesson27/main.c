#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 1.5;
    float b = 333;
    float *p;
    p = &a;
    *p = 3.1413;
    p = &b;
    *p = 2.718;

    printf("%f\n%f\n", a, b);
    return 0;
}
