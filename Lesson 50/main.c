#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

void func(int a, int b, int c)
{
    printf("%d %d %d\n", &a, &b, &c);
    int *ptr = &a + 1;
    printf("%d\n", *(ptr++) );
    printf("%d\n", *(ptr++) );
}

#define sum(a, ...) summa(a, __VA_ARGS__)

double summa(int cnt, ...)
{
    double res = 0;
    va_list ptr;
    va_start(ptr, cnt);
    for (; cnt > 0; cnt--)
        res += va_arg(ptr, double);
    va_end(ptr);
    return res;
}

void SuperMegaPrint(char *prm, ...)
{
    va_list ptr;
    va_start(ptr, prm);
    while (*prm)
    {
        if (*prm == 'i')
            printf("--%d--\n", va_arg(ptr, int) );
        else if (*prm == 'd')
            printf("--%f--\n", va_arg(ptr, double) );
        else if (*prm == 'c')
            printf("--%c--\n", va_arg(ptr, int) );
        else if (*prm == 's')
            printf("--%s--\n", va_arg(ptr, char) );
        prm++;
    }
    va_end(ptr);
}

int main()
{
    int a = 100;
    printf("%f\n", sum(3, 5.1, 6.2, (double)a) );
    printf("%f\n", sum(5, 1.0, 2.0, 3.0, 4.0, 5.0) );
    SuperMegaPrint("isdc", 111, "Xardamarius kodit!!!", 456.456, 'S');
    return 0;
}
