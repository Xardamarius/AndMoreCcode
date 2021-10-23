#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *f = fopen("001.txt", "r");
    int i;
    while (!feof(f))
    {
        if (fscanf(f, "%d", &i) > 0)
        {
            i *= 2;
            printf("%d\n", i);
        }
        /*if (fgets(c, 1000, f) != NULL)
            printf("%s", c);*/
    }
    fclose(f);

    return 0;
}



/*
int main()
{
    FILE *f = fopen("001.txt", "w");
    for (int i = 0; i < 10; i++)
        fprintf(f, "%s", "sdfsdfsdfsdf ete fdgdfgd\n");
    fclose(f);

    return 0;
}
*/

/*
int main()
{
    FILE *f;
    char c[1000];
    int i;
    float a;

    f = fopen("001.txt", "w");
        fprintf(f, "%d\n", 100);
        fprintf(f, "%g\n", 2.5);
        /*fprintf(f, "%s", "Hello World!!!\n");
        fprintf(f, "%s", "Hello Moto!!!\n");*/

/*    fclose(f);

    f = fopen("0012.txt", "r");
    if (f == NULL)
        printf("fopen Read Error!");
    else
    {
        fscanf(f, "%d", &i);
        fscanf(f, "%g", &a);
        printf("%d %g\n", i, a);
    }

    /*while(!feof(f))
    {
        if(fscanf(f, "%s", c) > 0)
        /*fscanf(f, "%s\n", c);*/
        /*if (fgets(c, 1000, f) != NULL)*/
        /*fscanf(f, "%s", c);*/
        /*printf("%s\n", c);
    }*/

/*    fclose(f);

    return 0;
}
*/
