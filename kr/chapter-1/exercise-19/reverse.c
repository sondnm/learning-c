#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
int reverse(char line[], int length);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int reverse(char s[], int length)
{
    int j;
    char reverse_line[length];

    for (j = length - 2; j >= 0; --j) {
        reverse_line[j] = s[length - 2 - j];
    }

    for (j = 0; j < length - 1; ++j) {
        s[j] = reverse_line[j];
    }
    s[length] = '\n';
    s[length] = '\0';
    return 0;
}
