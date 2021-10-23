#include <stdio.h>
#include <stdlib.h>

struct sPoint{
    int x,y;
} p;

typedef struct sPoint TPoint;

int main()
{
    TPoint a[10];
    a[0].y = 9;
    printf("%d\n", a[0].y);

    return 0;
}
