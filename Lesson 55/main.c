#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    char *tmp;

    float a = strtof(argv[1], &tmp);
    if (*tmp)
    {
        printf("first argument must be a number.\n");
        return -1;
    }

    float b = strtof(argv[2], &tmp);
    if (*tmp)
    {
        printf("second argument must be a number.\n");
        return -1;
    }

    if (*argv[3] == '+')
        printf("%g + %g = %g", a, b, a + b);
    else if (*argv[3] == '-')
        printf("%g - %g = %g", a, b, a - b);
    else if (*argv[3] == 'x')
        printf("%g * %g = %g", a, b, a * b);
    else if (*argv[3] == '/')
        printf("%g / %g = %g", a, b, a / b);
    else
        printf("unknown operator %s\n", argv[3]);

    getchar();
    return 0;
}

/*
int main(int argc, char *argv[])
{
    char *tmp;

    float a = strtof(argv[1], &tmp);
    if (*tmp)
    {
        printf("first argument must be a number.\n");
        return -1;
    }

    float b = strtof(argv[2], &tmp);
    if (*tmp)
    {
        printf("second argument must be a number.\n");
        return -1;
    }

    if (*argv[3] == '+')
        printf("%g + %g = %g", a, b, a + b);
    else if (*argv[3] == '-')
        printf("%g - %g = %g", a, b, a - b);
    else if (*argv[3] == 'x')
        printf("%g * %g = %g", a, b, a * b);
    else if (*argv[3] == '/')
        printf("%g / %g = %g", a, b, a / b);
    else
        printf("unknown operator %s\n", argv[3]);

    getchar();
    return 0;
}
*/
/*
#define A 0b0001
#define B 0b0010
#define C 0b0100
#define D 0b1000

char tmp = A | D;

int main()
{
    printf("%x\n", tmp);
    if ((tmp & A) && (tmp & C))
        printf("OK!\n");

    return 0;
}
*/
/*
struct {
    unsigned char a : 1;
    unsigned char b : 1;
    unsigned char c : 1;
    unsigned char d : 1;
} tmp = {1,0,1,1};

int main()
{
    printf("%d%d%d%d\n", tmp.a, tmp.b, tmp.c, tmp.d);
    if (tmp.a && tmp.c && !tmp.b && !tmp.d)
        printf("OK!\n");

    return 0;
}
*/
/*
struct {
    unsigned char a2 : 2;
    char b2 : 2;
    unsigned char a4 : 4;
    char b4 : 4;
} tmp;

int main()
{
    for (int i = 0; i < 16; i++)
    {
        tmp.a2 = tmp.b2 = tmp.a4 = tmp.b4 = i;
        printf("%5d%5d%5d%5d\n", tmp.a2, tmp.b2, tmp.a4, tmp.b4 );
    }

    return 0;
}
*/
/*
int main()
{
    unsigned char a = 0x70;
    if (a & (1 << (sizeof(a)*8-1) ) )
        printf("%x\n", a);

    return 0;
}
*/
/*
int main()
{
    unsigned int a = 0xf0ffffff;
    if (a & (1 << (sizeof(a)*8-1) ) )
        printf("%x\n", a);

    return 0;
}
*/
/*
int main()
{
    unsigned char a = 0x7A;
    if (a & 0x80)
        printf("%x\n", a);

    return 0;
}
*/
/*
int main()
{
    unsigned char a = 0xAA;
    a = a & 0x0f;
    printf("%x\n", a);

    unsigned char b = 0xAA;
    b = b | 0x0f;
    printf("%x\n", b);

    unsigned short c = (b << 8) | a;
    printf("%x\n", c);

    return 0;
}
*/
