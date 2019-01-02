#include <stdio.h>
#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {
        printf("The longest printable line is: \n");
        printf("%s\n", longest);
        printf("And the longest line's length is: %d\n", max);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF &&  c != '\n'; ++i)
        if (i < lim - 1)
            s[l++] = c;
    if (c == '\n') {
        if (l < lim - 1)
            s[l++] = c;
        ++i;
    }
    s[l] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
