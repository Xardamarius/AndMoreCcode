#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <winuser.h>

int main()
{
    setlocale(LC_ALL, "Russian");

/*    char ch = 'w';
    printf("%с", ch);

    ch = getch();
    printf("ch = %c", ch); */

    char s[20] = "фывавава";
    s[0] = '7';
    printf("%s\n", s);

    sprintf(s, "1212121212");
    s[4] = '\0';
    printf("%s\n", s);

    gets(s);
    OemToChar(s, s);
    printf("%s\n", s);

    return 0;
}
