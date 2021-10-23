#include <stdio.h>
#include <stdlib.h>


typedef int * TmasPI[5];
typedef TmasPI * T2();

int k = 11;
TmasPI mas;
TmasPI *func(){ return &mas;}
T2 * masf[5];

int main()
{
    mas[3] = &k;
    masf[1] = func;

    printf("%d\n", *(*masf[1]())[3] );

    return 0;
}

/*
int k = 11;
int * mas[5];
int * (*func())[5] { return &mas;}
int * (*(*masf[5])())[5];

int main()
{
    mas[3] = &k;
    masf[1] = func;

    printf("%d\n", *(*masf[1]())[3] );

    return 0;
}
*/
/*
int func1(int x) { return x; }

typedef int Tfunc1(int);
Tfunc1 * var1 = func1;
Tfunc1 ** func3() { return &var1; }

typedef Tfunc1 ** (*Ttest)();
Ttest test(char c) { printf("%c\n", c); return func3; }

int main()
{
    printf("%d\n", (*test('A')())(33) );

    return 0;
}
*/
/*
int func1(int x) { return x; }

typedef int Tfunc1(int);
Tfunc1 * var1 = func1;
Tfunc1 ** func3() { return &var1; }

typedef Tfunc1 ** (*Ttest)();
Ttest test() { return func3; }

int main()
{
    printf("%d\n", (*test()())(33) );

    return 0;
}
*/
/*
int func1(int x) { return x; }

typedef int Tfunc1(int);
Tfunc1 * var1 = func1;
Tfunc1 ** func3() { return &var1; }

Tfunc1 ** (*test())() { return func3; }

int main()
{
    printf("%d\n", (*test()())(33) );

    return 0;
}
*/
/*
int k = 8;
int pk = &k;
int ** GetPInt() { return &pk; }

int **(*test())() { return GetPInt; }


int main()
{
    int **(*(*func)())();
    func = test;
    printf("%d\n", **test()());

    return 0;
}
*/
/*
int main()
{
    int a = 5;
    int *pa = &a;

    typedef int **ppInt;
    ppInt mas[5];
    mas[2] = &pa;

    ppInt (*pmas)[5];
    pmas = &mas;
    ppInt (**ppmas)[5];
    ppmas = &pmas;

    printf("%d\n", **(**ppmas)[2] );

    return 0;
}
*/
/*
int main()
{
    int a = 5;
    int *pa = &a;

    typedef int **ppInt;
    ppInt mas[5];
    mas[2] = &pa;

    ppInt (*pmas)[5];
    pmas = &mas;
    ppInt (**ppmas)[5];
    ppmas = &pmas;

    printf("%d\n", **(**ppmas)[2] );

    return 0;
}
*/
/*
int main()
{
    int mas[5];
    mas[3] = 7;

    typedef int (*Tmas7[5])[5];
    Tmas7 mas7;
    mas7[1] = &mas;
    printf("%d\n", (*mas7[1])[3] );

    typedef int T1[5];
    typedef T1 * T2[5];
    typedef T2 * Tmas8;
    Tmas8 mas8;
    mas8 = &mas;
    (*mas8)[2] = &mas;
    printf("%d\n", (*(*mas8)[2])[3] );

    return 0;
}
*/
/*
int main()
{
    int mas[5];
    mas[3] = 7;

    int (*mas7[5])[5];
    mas7[1] = &mas;
    printf("%d\n", (*mas7[1])[3] );

    int (*(*mas8)[5])[5];
    mas8 = &mas;
    (*mas8)[2] = &mas;
    printf("%d\n", (*(*mas8)[2])[3] );

    return 0;
}
*/
/*
int main()
{
    int a[5] = {10,2,3,4,15};
    int tmp;
    for (int i = 0; i < 2; tmp = a[i], a[i] = a[4-i], a[4-i] = tmp, i++);
    int i = 0;
    while (printf("%d\n", a[i]), ++i < 5);

    return 0;
}
*/
/*
int main()
{
    int a[5] = {10,2,3,4,15};
    int i = 0;
    while (printf("%d\n", a[i]), ++i < 5);

    return 0;
}
*/

/*
int main()
{
    int a = 5;
    int b = 20;
    printf("%d  %d\n", a, (b += a, a = b - a, b -= a, b) );

    return 0;
}
*/
/*
int main()
{
    int a = 5;
    int b = 20;
    b += a, a = b - a, b -= a;
    printf("%d  %d\n", a, b);

    return 0;
}
*/
/*
int main()
{
    int * const a = malloc(sizeof(int) * 2);
    a[0] = 1;
    a[1] = 7;
    int **b = &a;
    *b = malloc(sizof(int) * 5);
    printf("%d %d\n", a[0], a[1]);

    return 0;
}
*/
/*
int main()
{
    int * const a = malloc(sizeof(int) * 2);
    a[0] = 1;
    a[1] = 7;
    a = malloc(40);
    printf("%d %d\n", a[0], a[1]);

    return 0;
}
*/
/*
typedef struct {
    float x,y;
} point;

void proc(point const p)
{
    p.x = 5;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
*/


/*
int test(int * const x, int const * y)
{
    x = 12;
    *y = 33;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
*/
