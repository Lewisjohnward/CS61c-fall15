#include <stdio.h>

/* Swaps the value of two ints outside of this function. */
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/* Increments the value of an int outside of this function by one */
void increment(int *a)
{
    *a = *a + 1;
}

/* Returns the number of bytes in a string. Does not use strlen .*/
int byte_count(char *arr)
{
    int i = 0;
    int count = 0;
    while(*(arr + i) != '\0')
    {
        count++;
        i++;
    }
    /*Add one for null character*/
    count++;
    return count;
}

int main (void)
{
    int a = 5;
    int b = 10;
    char arr[] = "hello";
    int bytes;
    printf("before a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("after swap a: %d, b: %d\n", a, b);
    increment(&a);
    printf("after increment a: %d, b: %d\n", a, b);
    bytes = byte_count(arr);
    printf("bytes in string: %d\n", bytes);
    return 0;
}
