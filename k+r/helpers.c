#include <stdio.h>

/*
Record input character-by-character from stdin in s
until n-1 characters are read or EOF is reached.
Explicitly end s with a null terminator.
*/
void input(char *s, int n)
{
    int i, c;
    for (i = 0; i < n - 1 && (c = getchar()) != EOF; ++i)
        s[i] = c;
    s[i] = '\0';
}

/*
Record input character-by-character from stdin in s until n-1
characters are read, a newline is read, or EOF is reached.
Explicitly end s with a null terminator.
*/
void line(char *s, int n)
{
    int i, c;
    for (i = 0; i < n - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
}

/* Return 1 of c is a whitespace character and 0 otherwise. */
int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\x0b' || c == '\x0c');
}
