#include <stdio.h>
#include <stdlib.h>

struct SPoint {
    int x;
    int y;
    char c[10];
};

typedef struct SPoint TPoint;

void ShowPoint(TPoint point)
{
    printf("x = %d      y = %d      c = %s\n", point.x, point.y, point.c);
    for (int i = 0; i<10; i++)
        printf("%d\n", point.c[i]);
}

void SetPoint(TPoint *pointPtr, int xPos, int yPos, char cStr[10])
{
    if (pointPtr != NULL)
    {
        (*pointPtr).x = xPos;
        (*pointPtr).y = yPos;
        for (int i = 0; i<10; i++)
            (*pointPtr).c[i] = cStr[i];
    }
}

int main()
{
    TPoint p;
    TPoint *pPtr = NULL;

    p.x = 3;
    p.y = 7;
    pPtr = &p;

    SetPoint(pPtr, 11, 22, "trololo");
    ShowPoint(*pPtr);

    return 0;
}
