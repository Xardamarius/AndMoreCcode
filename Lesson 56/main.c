#include <stdio.h>
#include <stdlib.h>

int main()
{
    int const mas[5] = {1,2,3,4,5};
    mas[2] = 7;
    return 0;
}

/*
typedef struct {
    int x;
    int const y;
} point;

int a = 33;

int main()
{
    point p = {5, &a};
    point pp = {11, &a};
    p = pp;
    printf("%d %d\n", p.x, *p.y);
    return 0;
}
*/
