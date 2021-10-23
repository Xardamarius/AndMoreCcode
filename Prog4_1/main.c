#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x,y,z;
    char name[50];
    char color[20];
} TBox;

int main()
{
    TBox box[3];

    for (int i=0; i<3; i++)
    {
        box[i].x = rand() % 100;
        box[i].y = rand() % 100;
        box[i].z = rand() % 100;
    }
        sprintf(box[0].name, "chair");
        sprintf(box[0].color, "green");
        sprintf(box[1].name, "table");
        sprintf(box[1].color, "red");
        sprintf(box[2].name, "something strange");
        sprintf(box[2].color, "blue");

        for (int i=0; i<3; i++)
            printf(" name = %s\n  x = %d\n  y = %d\n  z = %d\n  color = %s\n",
                   box[i].name, box[i].x, box[i].y, box[i].z, box[i].color);
    return 0;
}
