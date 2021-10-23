#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width = 5;
    int height = 3;
    int *mas = 0;
    mas = malloc( sizeof(*mas) * width * height);

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            mas[j*width + i] = 100*j + i;

    int oldWidth = width;
    width = 4;
    int *tmp = malloc( sizeof(*mas)* width * height );
    for (int i = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            if (i < oldWidth)
                tmp[j*width + i] = mas[j*oldWidth + i];
    free(mas);
    mas = tmp;
    tmp = 0;

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            printf("%d\t%s", mas[j*width + i], (i == width-1) ? "\n" : "");

    free(mas);

    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int width = 5;
    int height = 3;
    int **mas = 0;
    mas = malloc( sizeof(*mas) * width);
    for (int i = 0; i < width; i++)
        mas[i] = malloc( sizeof(**mas) * height );

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            mas[i][j] = 100*j + i;

    int oldWidth = width;
    width = 6;

    if (oldWidth < width)
    {
        mas = realloc( mas, sizeof(*mas)* width );
        for (int i = oldWidth; i < width; i++)
            mas[i] = malloc( sizeof(**mas) * height );
    }

    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            printf("%d\t%s", mas[i][j], (i == width-1) ? "\n" : "");

    for (int i = 0; i < width; i++)
        free(mas[i]);

    free(mas);

    return 0;
}
*/
