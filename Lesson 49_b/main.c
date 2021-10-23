#include <stdio.h>
#include <stdlib.h>

enum Color { clRed = 3, clGreen, clBlue = 8 } clr;
typedef enum Color TColor;

int main()
{
    //enum MyChar { MC_BIG_A = 'A', MC_SMALL_B = 'b', clGreen = 111 };
    //int clGreen = 777;
    //clr = clGreen;
    //TColor clr = clBlue;
    TColor clr = 1234;
    printf("%d\n", clr);
    //int a = clBlue;
    //printf("%d %d %c\n", clr, MC_BIG_A, MC_SMALL_B);
/*
    clr = clGreen;
    if ( clr == clRed)
        printf("Red");
    else if (clr == clGreen)
        printf("Green");
    else if (clr == clBlue)
        printf("Blue");
*/
    return 0;
}
