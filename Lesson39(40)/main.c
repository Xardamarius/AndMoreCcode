#include <stdio.h>
#include <stdlib.h>



int main()
{
    int mas[] = {1,2,26,4,5};
    FILE *f;

    f = fopen("001.txt", "wb");
        fwrite(mas, 1, sizeof(mas), f);
    fclose(f);

    int buf[5];
    f = fopen("001.txt", "rb");
        fread(buf, 1, sizeof(buf), f);
    fclose(f);

    for (int i = 0; i < 5; i++)
        printf("%d\n", buf[i]);

    return 0;
}



/*
#include <fcntl.h>

int main()
{
    FILE *f;

    _fmode = _O_BINARY;
    printf("%s\n", _fmode == _O_TEXT ? "TEXT" : "BINARY");

    char c[3] = "AB";
    c[1] = 26;

    f = fopen("001.txt", "w");
        fprintf(f, c);
    fclose(f);

    char buf[10] = "";

    f = fopen("001.txt", "r");
        fread(buf, 1, sizeof(buf), f);
    fclose(f);

    for (int i = 0; i < 10; i++)
        printf("%d\n", buf[i]);

    return 0;
}
*/
