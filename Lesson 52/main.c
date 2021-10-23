#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char a = 0b1100;
    a = a | 0b111;
    printf("%x\n", a);
    return 0;
}
