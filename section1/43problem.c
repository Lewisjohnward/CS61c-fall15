#include <stdio.h>
#include <string.h>

/*
 * Copes the string SRC to DST 
 */

void copy(char *src, char *dst)
{
    while(*(dst++) = *(src++));
}

int main (void)
{
    char src[] = "hello";
    char dst[strlen(src)];
    copy(src, dst);
    printf("%s\n", dst);
    return 0;

}
