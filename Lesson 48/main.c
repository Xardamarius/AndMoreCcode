#include <stdio.h>
#include <stdlib.h>

#define Anton
#ifdef Anton
    #define myMult(a,b) (a)*(b)
#endif

//#undef myMult

int main()
{
    //#if width > 10
    #ifdef myMult
        printf("%d\n", myMult(5+5,7) );
    #else
        #error макроса нету :-)
    #endif
    return 0;
}
