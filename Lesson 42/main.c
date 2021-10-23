#include <stdio.h>
#include <stdlib.h>


void f1()
{
    int b = 1;
    b += 5;
    printf("%d\n", b);
}

int main()
{
    int i = 4;
    f1();
    f1();
    scanf("%d", &i);
    return 0;
}

/*
typedef struct {
    int x,y;
    char name[20];
} T1;

int main()
{
    int i = 4;
    int k[] = {1,2,3,44,55};
    printf("%d", k[0]);
    scanf("%d", &i);
    return 0;
}
*/
