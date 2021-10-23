#include <stdio.h>
#include <stdlib.h>

struct SPoint {
    int x,y;
};

struct SSize {
    int width, height;
};

struct SShape {
    char *name;
    struct { int x,y; };
    union
    {
        struct SSize;
        float radius;
    } size;
};



int main()
{

    struct SShape shape = {"quad", 10, 20, 0, 0};
    shape.size.radius = 55;
    printf("%s %d %d %f\n", shape.name, shape.x, shape.y, shape.size.radius);

    return 0;
}
