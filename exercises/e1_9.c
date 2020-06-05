/*
Author: Eric Latham
My (polished) solution to K+R exercise 1-9:
    Write a program to copy its input to its output, replacing
    each string of one or more blanks by a single blank.
*/

#include <stdio.h>
#include <string.h>
#include "helpers.h"

#define N BUFSIZ /* input character limit */
#define IN 1     /* value associated with being in space */
#define OUT 0    /* value associated with being out of space */

int main()
{
    int i;       /* input index variable */
    int c;       /* character variable */
    int status;  /* whether or not we're in space */
    char inp[N]; /* array for input characters */

    input(inp, N);

    i = -1;
    status = OUT;
    while ((c = inp[++i]) != '\0')
    {
        if (status == OUT)
        {
            if (c == ' ')
                status = IN;
            putchar(c);
        }
        else if (c != ' ')
        {
            status = OUT;
            putchar(c);
        }
    }

    return 0;
}
