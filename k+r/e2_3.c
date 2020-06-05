/*
Author: Eric Latham
My solution to K+R exercise 2-3:
    Write a function my_htoi(s), which converts a string of hexadecimal digits
    (including an optional 0x or 0X) into its equivalent integer value.
    The allowable digits are 0-9, a-f, and A-F.
*/

#include <stdio.h>
#include <stdlib.h> /* exit */
#include "helpers.h"

int my_atoi(char *a);
int my_htod(char c);
int my_htoi(char *h);

int main()
{
    char n[BUFSIZ];

    /* test my_atoi */
    printf("test my_atoi(\"-987654321 is the number\"): %d (should be -987654321)\n",
           my_atoi("-987654321 is the number"));
    printf("test my_atoi(\"the number is 123456789\"): %d (should be 0)\n",
           my_atoi("the number is 123456789"));
    printf("test my_atoi(\"\t55\"): %d (should be 55)\n",
           my_atoi("\t55"));

    /* test my_htoi */
    printf("test my_htoi(\"0xabcdef\"): %d (should be 11259375)\n",
           my_htoi("0xabcdef"));
    printf("test my_htoi(\"123ABC\"): %d (should be 1194684)\n",
           my_htoi("123ABC"));
    printf("test my_htoi(\"\t0XffffFFF6\"): %d (should be -10)\n",
           my_htoi("\t0XffffFFF6"));

    for (;;)
    {
        /* let user test my_atoi */
        printf("enter a decimal number n: ");
        line(n, BUFSIZ);
        printf("result of my_atoi(n): %d\n", my_atoi(n));

        /* let user test my_htoi */
        printf("enter a hexidecimal number n: ");
        line(n, BUFSIZ);
        printf("result of my_htoi(n): %d\n", my_htoi(n));
    }

    return 0;
}

/* Return the integer represented by the given decimal string. */
int my_atoi(char *a)
{
    int n;  /* result */
    int s;  /* result sign (1 or -1) */
    int i;  /* input read head */
    char c; /* input character variable */

    for (i = 0; is_space(a[i]); ++i)
        ;

    if (a[i] == '-')
    {
        s = -1;
        ++i;
    }
    else
        s = 1;

    for (n = 0; (c = a[i]) >= '0' && c <= '9'; ++i)
        n = n * 10 + c - '0';

    return s * n;
}

/* Return the integer represented by the given hexadecimal character. */
int my_htod(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
    {
        fprintf(stderr, "my_htod: invalid hexadecimal character '%c'\n", c);
        exit(-1);
    }
}

/* Return the integer represented by the given hexadecimal string. */
int my_htoi(char *h)
{
    int n;  /* result */
    int i;  /* input read head */
    char c; /* input character variable */

    for (i = 0; is_space(h[i]); ++i)
        ;

    if (h[i] == '0') /* if h starts with 0, ensure it starts with 0x or 0X */
    {
        if (h[++i] != 'x' && h[i] != 'X')
        {
            fprintf(stderr, "my_htoi: invalid hexadecimal string \"%s\"\n", h);
            exit(-1);
        }
        ++i;
    }

    for (n = 0; (c = h[i]) != '\0'; ++i)
        n = n * 16 + my_htod(c);

    return n;
}
