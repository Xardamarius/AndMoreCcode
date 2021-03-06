#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>

double srednee(char *prm, ...)
{
    double res = 0;
    int cnt = 0;
    va_list ptr;
    va_start(ptr, cnt);
    while(*prm)
    {
        res += (*prm) == 'i' ? va_arg(ptr, int) : va_arg(ptr, double);
        cnt++;
        prm++;
    }
    va_end(ptr);
    return res / cnt;
}

int main()
{
    printf("%f\n", srednee("iiddi", 1, 2, 3.333, 4.222, 5));
    return 0;
}

/*
#include <stdarg.h>

double srednee(int cnt, ...)
{
    int res = 0;
    va_list ptr;
    va_start(ptr, cnt);
    for (int i = 0; i < cnt; i++)
        res += va_arg(ptr, int);
    va_end(ptr);
    return res / (float)cnt;
}

int main()
{
    printf("%f\n", srednee(5, 1,2,3,4,6));
    return 0;
}
*/

/*
typedef enum { opPlus, opMinus, opMult } TOper;

int operation(int a, int b, TOper oper)
{
    if (oper == opMinus) return a - b;
    else if (oper == opMinus) return a * b;
    else return a + b;
}


#define work1

#ifdef work1
    #define sqr(a) a*a
    #define mod(a) ((a) < 0 ? -(a) : (a))
#else
    #error ?? ?????? ??????
#endif

#define lenght 70
#if lenght < 10
    #error ??????!!!
#endif // lenght
*/
/*
int main()
{
    /*
    int i = 0;
    #ifdef sqr
        i = sqr(5);
    #endif // sqr
    printf("%d\n", i);
    printf("%d\n", mod(5-25));
    printf("%d\n", mod(15));*//*
    printf("%d\n", operation(10, 5, opPlus));
    printf("%d\n", operation(10, 5, opMinus));
    printf("%d\n", operation(10, 5, opMult));
    return 0;
}*/
