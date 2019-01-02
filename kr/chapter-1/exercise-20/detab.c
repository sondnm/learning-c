#include <stdio.h>
#define MAXLINE 1000
#define SPACE ' '
#define TAB '\t'
#define TABSIZE 4

int get_line(char line[], int maxline);
void detab(char buffer[], char line[], int tabsize);

int main()
{
    char buffer[MAXLINE];
    char line[MAXLINE];

    while (get_line(buffer, MAXLINE) > 1) {
        detab(buffer, line, TABSIZE);
        printf("%s", line);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void detab(char buffer[], char line[], int tabsize)
{
    int i, j, k, l, c;

    i = l = 0;
    while ((c = buffer[i++]) != '\0') {
        if (c == TAB) {
            j = tabsize - (l % tabsize);
            for (k = 0; k < j; k++) {
                line[l++] = SPACE;
            }
        } else {
            line[l++] = c;
        }
    }
    line[l] = '\0';
}
