#include <stdio.h>
#include <stdlib.h>


typedef struct SMan{
    char name[20];
    int height;
} TMan;

void InitMan(TMan *man, char *name, int height)
{
    sprintf(man->name, "%s", name);
    /*man->name = name;*/
    man->height = height;
}

int main()
{
    TMan man[3] = { {"Nikola", 180}, {"James", 185}, {"Henry", 190} };

    InitMan(man+1, "Thomas", 175);

    for (int i = 0; i < 3; i++)
        printf("   Name = %s\nHeight = %d\n\n", man[i].name, man[i].height);

    return 0;
}

/*
typedef struct SMan{
    char *name;
    int height;
} TMan;

int main()
{
    TMan man = {"Nikola", 180};

    TMan *pman;
    pman = &man;
    pman->name = "James";
    pman->height = 185;

    printf("   Name = %s\nHeight = %d\n\n", man.name, man.height);

    return 0;
}
*/
/*
int main()
{
    char c[2][20] = {"sdsdsdsds", "aaaa"};
    printf("size = %d\n", sizeof(c));
    for (int i = 0; i < 2; i++)
        printf("%s\n", c[i]);

    return 0;
}
*/
/*
int main()
{
    float mas[] = {2.5, 3.6, 4.6, 5.7, 6.8};
    int cnt = sizeof(mas) / sizeof(mas[0]);
    cnt--;
    for (;cnt >= 0; cnt--)
        printf("%g\n", mas[cnt]);
    return 0;
}
*/

/*
struct Sintchar {
    int x;
    char c;
};

typedef struct Sintchar Tintchar, *Pintchar;

int main()
{
    int mas[3][2] = {{1,2},{11,22},{44,77}};

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 2; i++)
            printf("%d ", mas[j][i]);
        printf("\n");
    }

    return 0;
}
*/



/*

struct Sintchar {
    int x;
    char c;
};

typedef struct Sintchar Tintchar, *Pintchar;

int main()
{
    Tintchar ic[2] = { {10, 'A'}, {33, 'S'}, {100, 'I'} };

    int len = sizeof(ic) /sizeof(ic[0]);

    for (int i = 0; i < 2; i++)
        printf("%d %c\n", ic[i].x, ic[i].c);

    return 0;
}
*/

/*

struct Sintchar {
    int x;
    char c;
};

typedef struct Sintchar Tintchar, *Pintchar;

int main()
{
    Tintchar ic[2] = { {10, 'A'}, {33, 'S'} };

    for (int i = 0; i < 2; i++)
        printf("%d %c\n", ic[i].x, ic[i].c);

    return 0;
}
*/
/*

struct Sintchar {
    int x;
    char c;
};

typedef struct Sintchar Tintchar;

int main()
{
    Tintchar ic = {10, 'A'};
    Tintchar *pic;

    pic = &ic;
    pic->x = 55;
    pic->c = 'F';

    printf("%d %c", ic.x, ic.c);

    return 0;
}
*/


/*

int main()
{
    int mas[] = {1,2,3,40, 5,6,7,80, 9, 0};

    int len = sizeof(mas) / sizeof(mas[0]);

    for (int i = 0; i < len; i++)
        printf("%d\n", mas[i]);

    return 0;
}
*/


/*
typedef int celoe, *pCeloe;

int main()
{
    celoe i = 7;
    pCeloe pi;

    pi = &i;
    *pi = 10;

    printf("%d\n", i);

    return 0;
}
*/
