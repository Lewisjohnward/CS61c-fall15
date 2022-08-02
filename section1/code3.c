
/*
 * This performs bitwise XOR operation
 *
 *
 */

#include <stddef.h>
#include <stdio.h>


int baz(int x, int y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

int main (void)
{
    int i[LEN] = {5, 0, 4, 3, 2, 5, 0, 0};
    int res;
    res = baz(i, LEN);
    printf("%d\n", res);

    return 0;
}
