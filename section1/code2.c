/*
 * This function sums the number of zeros in the array returns 0 if there is none otherwise a negative number if true with the quantity equal to the num of zeros
 *
 *
 */

#include <stddef.h>
#include <stdio.h>
#define LEN 8


int bar(int *arr, size_t n)
{
    int sum = 0, i;

    for (i = n; i > 0; i--)
    {
        sum += !arr[i - 1];
    }
    return ~sum + 1;
}

int main (void)
{
    int i[LEN] = {5, 0, 4, 3, 2, 5, 0, 0};
    int res;
    res = bar(i, LEN);
    printf("%d\n", res);

    return 0;
}
