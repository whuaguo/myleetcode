#include <stdio.h>

#define twice(x) (      \
    {                   \
        int y = x << 1; \
        y;              \
    })

int main()
{
    printf("twice of 5 is %d!\n", twice(5));

    return 0;
}