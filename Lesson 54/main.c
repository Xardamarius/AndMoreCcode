#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    while(*argv)
        printf("-- %s --\n", *argv++);

    char *c;
    int i = strtol("123ddfdf", &c, 10);
    printf("%d %s\n", i, c);

    getchar();
    return 0;
}

/*
int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        char *c;
        int f = strtol(argv[i], &c, 10);
        printf("%s -- %s --\n", *c == 0 ? " int" : "string", argv[i]);
    }
    getchar();
    return 0;
}
*/
