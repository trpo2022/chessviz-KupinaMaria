#include <lib/gorizontal.h>
int gorizontal(int y)
{
    int i, flag1 = 0;
    for (i = 1; i < 9; i++) {
        if (y == i)
            flag1 = 1;
    }
    if (flag1 == 0)
        return 1;
    else
        return 0;
}