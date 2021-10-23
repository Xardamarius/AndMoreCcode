#include <stdio.h>
#include <stdlib.h>

typedef struct s1{
    int x,y;
}T1;

typedef struct S2{
    char info[20];
    T1 pos;
}T2;

int main()
{
    FILE *f;
    T2 a = {"test1", {123, 45}};

    f = fopen("001.txt", "w");
        fwrite(&a, 1, sizeof(a), f);
    fclose(f);

    T2 buf;
    f = fopen("001.txt", "r");
        fread(&buf, 1, sizeof(buf), f);
        printf("%s %d %d", buf.info, buf.pos.x, buf.pos.y);
    fclose(f);

    return 0;
}


/*
int main()
{
    FILE *f;
    int i = 555;
    float fl = 36.6;
    char c[20] = "Antoxa";

    f = fopen("001.txt", "w");
        fwrite(&i, l, sizeof(i), f);
        fwrite(&fl, l, sizeof(fl), f);
        fwrite(c, l, sizeof(c), f);
    fclose(f);

    int i_buf;
    float f_buf;
    char c_buf[20];

    f = fopen("001.txt", "w");
        fread(&i_buf, l, sizeof(i_buf), f);
        fread(&f_buf, l, sizeof(f_buf), f);
        fread(c_buf, l, sizeof(c_buf), f);
        printf("%d %f %s", i_buf, f_buf, c_buf);

    fclose(f);

    return 0;
}
*/
/*
int main()
{
    FILE *f;
    div_t mas[] = {{11,111}, {2,2222}, {33,44}};

    f = fopen("001.txt", "w");
        fwrite(mas, 1, sizeof(mas), f);
    fclose(f);

    div_t buf;

    f = fopen("001.txt", "r");
    while (!feof(f))
    {
        if (fread(&buf, 1, sizeof(buf), f) > 0)
            printf("[%d, %d]\n", buf.quot, buf.rem);
    }

    fclose(f);

    return 0;
}
*/
/*
int main()
{
    FILE *f;
    int mas[] = {1,2,3,4,55,66,77};

    f = fopen("001.txt", "w");
        fwrite(mas, 1, sizeof(mas), f);
    fclose(f);

    int buf;

    f = fopen("001.txt", "r");
    while (!feof(f))
    {
        if (fread(&buf, 1, sizeof(buf), f) > 0)
            printf("%d\n", buf);
    }

    fclose(f);

    return 0;
}
*/
/*
int main()
{
    FILE *f;

    int cnt = 5;
    int *mas = malloc( sizeof(*mas) * cnt);
    for (int i = 0; i < cnt; i++)
        mas[i] = 100 + i;

    f = fopen("001.txt", "w");
        fwrite(mas, cnt, sizeof(*mas), f);
    fclose(f);

    int *buf = malloc(sizeof(*buf) * cnt);

    f = fopen("001.txt", "r");
        fread(buf, cnt, sizeof(*buf), f);
    fclose(f);

    for (int i = 0; i < cnt; i++)
        printf("%d\n", buf[i]);

    return 0;
}

*/

/*
typedef struct STest {
    int x,y;
    float f;
    char c[10];
}TTest;

int main()
{
    FILE *f;

    TTest i = {50, 88, 3.1413, "Pantomimia"};

    f = fopen("001.txt", "w");
        fwrite(&i, 1, sizeof(i), f);
    fclose(f);

    TTest buf;

    f = fopen("001.txt", "r");
        fread(&buf, 1, sizeof(buf), f);
    fclose(f);

    printf("%d %d %f %s\n", buf.x,buf.y, buf.f, buf.c);

    return 0;
}*/
