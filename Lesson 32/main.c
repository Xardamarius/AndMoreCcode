#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    time_t second;
    second = time(NULL);

    struct tm *datetime;
    datetime = localtime(&second);

    srand( datetime[0].tm_mday );

    switch (rand() % 5){
        case 0:
            printf("The Painted Veil\n");
            return;
        case 1:
            printf("WhipLash\n");
            return;
        case 2:
            printf("What Happens in Vegas\n");
            return;
        case 3:
            printf("The Game\n");
            return;
        case 4:
            printf("Mandariinid\n");
            return;
        default:
            printf("ERROR\n");
    }

    return 0;
}


/*
int GetInt()
{
    static int i = 0;
    return i++;
}

int main()
{
    printf("%d\n", GetInt() );
    printf("%d\n", GetInt() );
    printf("%d\n", GetInt() );

    return 0;
}
*/
/*int main()
{
    int val = 2;


    switch (val)
    {
        case 9:
            printf("999\n");
            break;
        case 7:
        case 6:
        case 5:
            printf("777\n");
            break;
        case 2:
            break;
        default:
            printf("None\n");
    }
    return 0;
}*/
