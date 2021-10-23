#include <stdio.h>
#include <stdlib.h>


int MyPow(int val, int pow)
{
    if(pow < 1) return 1;
    return val * MyPow(val, pow - 1);
}

int main()
{
    int i;
    i = MyPow(5, 2);
    printf("%d\n", i);

    return 0;
}





/*

int main()
{
    int i;
    scanf("%d", &i);

    i = i < 10 ? 10 : ( i > 100 ? 100 : i + 1000 );

    printf("%d\n", i);

    return 0;
}

*/

/*
void MyPrint(int cnt)
{
    printf("text\n");
    cnt--;
    if (cnt > 0)
        MyPrint(cnt);
}

int MyFactorial(int x)
{
    int res = 1;
    for (int i = 1; i <= x; i++)
        res *= i;
    return res;
}

int MyFactRec(int x)
{
    if (x > 1)
        return x * MyFactRec(x - 1);
    else
        return 1;
}


int main()
{
    printf("f1 = %d\n", MyFactorial(3));
    printf("f2= %d\n", MyFactRec(3));
    return 0;
}

*/

/* int main()
{
    int i;
    scanf("%d", &i);

    i = 50 + (i < 10 ? 10 : i * 2);

    printf("%d\n", i);
    return 0;
} */
