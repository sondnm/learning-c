#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 1)
            printf("%s", line);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i, j, trailing_blank_count;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    trailing_blank_count = 0;
    if (c == '\n') {
        for (j = i - 1; j >= 0; --j) {
            if (s[j] == ' ' || s[j] == '\t') {
                ++trailing_blank_count;
                s[j] = '\0';
            } else if (s[j] != ' ' && s[j] != '\t') {
                s[j + 1] = '\n';
                break;
            }
        }
        if (trailing_blank_count == 0)
            s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i - trailing_blank_count;
}
