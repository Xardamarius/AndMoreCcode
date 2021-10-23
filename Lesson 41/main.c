#include <stdio.h>
#include <stdlib.h>



int main()
{
    int mas[] = {1,2,3,4,5};
    FILE *f;

    f = fopen("001.txt", "wb+");
        fwrite(mas, 1, sizeof(mas), f);

        int a;
        fseek(f, sizeof(a) * 2, SEEK_SET);
        fread(&a, 1, sizeof(a), f);
    fclose(f);

    return 0;
}

/*
int main()
{
    char c[5] = {"abcde"};
    FILE *f;

    f = fopen("001.txt", "wb+");
        fwrite(c, 1, sizeof(c), f);

        fseek(f, 2, SEEK_SET);
        char buf;
        while (!feof(f))
        {
            if ( fread(&buf, 1, sizeof(buf), f) > 0 )
                printf("%c\n", buf);
        }

    fclose(f);

    return 0;
}*/


/*
int main()
{
    FILE *f;

    f = fopen("001.txt", "a+");

        fprintf(f, "zzzXXX");

        char c[100];
        fseek(f, 0, SEEK_SET);
        if (fgets(c, 100, f) != NULL)
            printf(c);
    fclose(f);

    return 0;
}
*/
