
/*
 *
 *
 * 
 * The following code segments have been fixed
 *
 */

#include <stdio.h>
#define LEN 4

int sum(int* summands, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += *(summands + i);
    return sum;
}

int main (void)
{
    int arr[LEN] = {4, 5, 4, 3};
    int res;
    res = sum(arr, LEN);
    printf("sum: %d\n", res);


    return 0;
}
