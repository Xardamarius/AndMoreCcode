#include <stdio.h>
#include <stdlib.h>

int m[5] = {1,2,3,4,5};
int (*fumas())[] { return &m; }
int (*(*varm1)())[] = fumas;

int f1() { return 20; }
int f2() { return 77; }
int (*masfu2[2])() = {f1, f2};

int (*(*fumasfu3())[2])() { return &masfu2; }

int main()
{
    printf("%d\n", (*fumas())[2] );
    printf("%d\n", (*varm1())[4] );

    printf("%d\n", masfu2[0]() );

    printf("%d\n", (*fumasfu3())[1]() );

    return 0;
}

/*
typedef int Tfunc1(int);
int func1(int x) { return x; }
Tfunc1 * var1;
Tfunc1 * func2() { return func1; }
Tfunc1 ** func3(){ return &var1; }


int main()
{
    var1 = func1;
    printf("%d\n", var1(11) );
    printf("%d\n", func2()(22) );
    printf("%d\n", (*func3())(33) );


    return 0;
}
*/
/*
int func1(int x) { return x; }
int (*var1)(int);
int (*func2())(int) { return func1; }
int (**func3())(int) { return &var1; }


int main()
{
    var1 = func1;
    printf("%d\n", var1(11) );
    printf("%d\n", func2()(22) );
    printf("%d\n", (*func3())(33) );


    return 0;
}
*/
/*
int main()
{
    int mas[5];
    mas[3] = 7;
    printf("%d\n", mas[3] );

    int a = 33;
    int * mas2[5];
    mas2[2] = &a;
    printf("%d\n", *mas2[2] );

    typedef int Tmas3[5];
    Tmas3 * Pmas3;
    Pmas3 = &mas;
    printf("%d\n", (*Pmas3)[3] );

    typedef int * Tmas4[4];
    Tmas4 * Pmas4;
    Pmas4 = &mas2;
    printf("%d\n", *(*Pmas4)[2] );

    int mas5[5][5];
    mas5[1][3] = 100;
    printf("%d\n", mas5[1][3] );

    int (*Pmas6)[5][5];
    Pmas6 = &mas5;
    printf("%d\n", (*Pmas6)[1][3] );

    int (*mas7[5])[5];
    mas7[1] = &mas;
    printf("%d\n", (*mas7[1])[3] );

    int (*(*mas8)[5])[5];
    mas8 = &mas7;
    (*mas8)[2] = &mas;
    printf("%d\n", (*(*mas8)[2])[3] );

    return 0;
}
*/
