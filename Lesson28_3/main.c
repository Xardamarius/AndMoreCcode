#include <stdio.h>
#include <stdlib.h>

typedef struct Spt {
    int x,y;
} TPoint;

int main()
{
    TPoint *p = NULL;
    p = malloc( sizeof(TPoint) );

    (*p).x = 10;
    (*p).y = 20;
    printf("%d  %d\n", (*p).x, (*p).y );
    return 0;
}
