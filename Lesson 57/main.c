#include <stdio.h>
#include <stdlib.h>



int main()
{
    float a = 1.33e2f;
    double b = 5E3;
    long double c = 314e-2L;
    __mingw_fprintf("%g %g %lg\n", a, b, c);
    return 0;
}

/*
int main()
{
    long double a = 5.0;
    long double b = 2.L;
    float c = 3.14F;
    float d = 8.f;
    printf("%d %d %d\n", sizeof(5.f), sizeof(5.), sizeof(5.L) );
    return 0;
}

*/
/*

int main()
{
    printf("%d %d\n", sizeof(123), sizeof(123000111000) );

    return 0;
}

*/
/*
int main()
{
    int a, b;
    for (a = 5, b = 10; a < 10; printf("%d %d\n", a, b), a++, b += 10);
    return 0;
}

*/
/*

int main()
{
    int a = 1;
    if (a += 3, a > 2)
        printf("%d\n", a);
    return 0;
}
*/
