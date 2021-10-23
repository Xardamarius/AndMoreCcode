#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **dyn = malloc( sizeof(*dyn) * 2);
    for (int i = 0; i < 2; i++)
        dyn[i] = malloc( sizeof(**dyn) * 3);
    dyn[0][0] = 11;
    dyn[1][2] = 66;

    printf("%d\n", dyn);
    printf("%d\n", *dyn);
    printf("%d\n", **dyn);
    printf("%d\n", dyn[1][2]);

    printf("\n");

    int mas[2][3] = {{1,2,3},{4,5,6}};

    printf("%d\n", &mas);
    printf("%d\n", mas);
    printf("%d\n", *mas);
    printf("%d\n", **mas);
    printf("%d\n", mas[1][2]);

    printf("\n");

    int *p = mas;
    //for (int i = 0; i < 6; i++)
        //printf("%d\n", p[i]);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 3; i++)
            printf("%d\n", p[j*3+i]);

    return 0;
}

/*
void fpdyn(int **m)
{
    printf("%d %d\n", m, *m);
    for (int i = 0; i < 5; i++)
        printf("%d\n", (*m)[i]);
}

int main()
{
    int mas[5] = {1,2,3,4,5};

    int *dyn = malloc( sizeof(*dyn) * 5);
    for (int i = 0; i < 5; i++)
        dyn[i] = i+11;

    for (int i = 0; i < 5; i++)
        printf("%d %d\n", mas[i], dyn[i]);
    printf("\n");

    void *p = mas;
    fpdyn(&p);

    return 0;
}
*/
