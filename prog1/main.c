#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y;
    float i;

    printf("input x=");
    scanf("%f", &x);
    printf("input y=");
    scanf("%f", &y);

    printf("oper: \n1 = *\n2 = +\n3 = /\n4 = -\nselect code = ");
    scanf("%f", &i);

    if (i == 1)
        printf("%f * %f = %f", x, y, x * y);

    if (i == 2)
        printf("%f + %f = %f", x, y, x + y);

    if (i == 3)
        printf("%f / %f = %f", x, y, x / y);

    if (i == 4)
        printf("%f - %f = %f", x, y, x - y);

    return 2;
}
