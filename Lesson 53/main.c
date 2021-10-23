#include <stdio.h>
#include <stdlib.h>

enum {BOLD = 0b0001, ITALIC = 0b0010, UNDERLINE = 0b0100};

union
{
    struct
        {
            unsigned char isBold : 1;
            unsigned char isItalic : 1;
            unsigned char isUnderline : 1;
        };
        unsigned char flags;
} textParam;

int main()
{
    textParam.flags = ITALIC | UNDERLINE;
    if (textParam.isBold)
        printf("Text is bold\n");
    if (textParam.isItalic)
        printf("Text is italic\n");
    if (textParam.isUnderline)
        printf("Text is underline\n");
    return 0;
}
