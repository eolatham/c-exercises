/*
Author: Eric Latham
My solution to K+R exercise 1-14:
    Write a program to print a histogram of the frequencies
    of different characters in its input.
*/

#include <stdio.h>
#include "helpers.h"

#define INPUTLEN BUFSIZ /* input character limit */
#define COUNTLEN 128    /* number of buckets for ASCII character counts */

int main()
{
    int i;              /* input index variable */
    int j;              /* character count bucket counter */
    int c;              /* character variable */
    char inp[INPUTLEN]; /* array for input characters */
    int cnt[COUNTLEN];  /* array for input character counts */

    input(inp, INPUTLEN); /* record input from stdin in inp */

    /* record character counts of inp in cnt */
    for (i = -1; (c = inp[++i]) != '\0'; ++cnt[c])
        ;

    /* look at each character count bucket */
    for (i = 0; i < COUNTLEN; ++i)
    {
        /* print histogram row if bucket is positive */
        if (cnt[i] > 0)
        {
            printf("%3d", i);
            for (j = 0; j < cnt[i]; ++j)
                putchar('-');
            putchar('\n');
        }
    }

    return 0;
}
