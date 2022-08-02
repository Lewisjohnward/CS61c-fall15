#include <stdio.h>
#include <string.h>

/*
 * Increments all the letters in the string STRING, held in an array of length N.
 * Does not mdofiy any other memory which has been previously allocated
 *
 */

void increment(char* string, int n)
{
    for (int i = 0; i < n ; i++)
        *(string + i) = *(string + i) + 1;
}

int main (void)
{
    char str[] = "hello";
    increment(str, strlen(str));
    printf("%s\n", str);
    return 0;
}
