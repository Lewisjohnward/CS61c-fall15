/*
 * This function recursively adds members of an array passed to foo
 *
 *
 */

#include <stddef.h>
#include <stdio.h>

int foo(int *arr, size_t n)
{
    return n ? arr[0] + foo(arr + 1, n - 1) : 0;

}
int main (void)
{
    int i[5] = {5, 4, 3, 2, 5};
    printf("%d\n", foo(i, 5));

    return 0;
}
