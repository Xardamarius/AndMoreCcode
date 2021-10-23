#include <stdio.h>
#include <stdlib.h>

float MySum(float a, float b)
{
    return a + b;
}

float MyMult(float a, float b)
{
    return a * b;
}

int main ()
{
    float tmp = 1;
    float (*func) (float, float);

    func = MyMult;
    tmp = func(5, 5);

    printf("%g\n", tmp);

    return 0;
}



/*

typedef int (*TFuncAB) (int, int);

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int GetOne(int mas[], TFuncAB fn)
{
    int val = mas[0];
    if (fn != NULL)
        for (int i = 1; i < 10; i++)
            val = fn(val, mas[i]);
    return val;
}

int main()
{
    int (*fn[2]) (int, int);
    fn[0] = max;
    fn[1] = min;

    printf("%d\n",fn[0](11,5) );
    printf("%d\n",fn[1](11,5) );

    return 0;
}
*/
