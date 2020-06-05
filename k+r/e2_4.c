/*
Author: Eric Latham
My solution to K+R exercise 2-4:
    Write an alternative version of squeeze(s1, s2) that deletes each
    character in s1 that matches any character in the string s2.
*/

#include <stdio.h>
#include "helpers.h"

void squeeze_char(char *s, char c);
void squeeze_str(char *s1, const char *s2);

int main()
{
    char s1[BUFSIZ];
    char s2[BUFSIZ];

    printf("enter a string s1: ");
    line(s1, BUFSIZ);
    printf("enter a string s2: ");
    line(s2, BUFSIZ);

    squeeze_str(s1, s2);
    printf("s1 with s2 squeezed out: %s\n", s1);

    return 0;
}

/* Delete all instances of c in s. */
void squeeze_char(char *s, char c)
{
    int i; /* s read head */
    int j; /* s write head */

    for (i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* Delete each character in s1 that matches any character in s2. */
void squeeze_str(char *s1, const char *s2)
{
    int i;  /* s2 read head */
    char c; /* s2 character variable */

    i = -1;
    while ((c = s2[++i]) != '\0')
        squeeze_char(s1, c);
}
