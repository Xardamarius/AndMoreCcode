#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str[100];
    snprintf(str, 100, "wewewe");

    char *str2;
    str2 = malloc (10);
    snprintf(str2, 10, "123456");

    int len = strlen(str) + strlen(str2) + 1;
    str2 = realloc(str2, sizeof(char) * len)
    snprintf(str2, len, "%s%s", str2, str);

    printf("%s\n%s\n", str, str2);
    return 0;
}

/*
int main()
{
    char str[100];
    snprintf(str, 100, "wewewe");

    char *str2;
    str2 = malloc (10);
    snprintf(str2, 10, "123456");

    snprintf(str, 100, "%s %c %s %f", str, 'A', str2, 3.1413);

    printf("%s\n%s\n", str, str2);
    return 0;
}
*/
/*
int main()
{
    char str[10];
    snprintf(str, 10, "%s", "1234512345www");
    printf("%s\n", str);
    return 0;
}
*/
/*
int main()
{
    char *str = "wewewew";
    str = "123";
    str = malloc( 10 );
    sprintf(str, "%s", "45454");
    free(str);
    str = "pppp";
    printf("%s\n", str);
    return 0;
}
*/
