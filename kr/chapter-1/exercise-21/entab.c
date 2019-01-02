#include <stdio.h>
#define MAXLINE 1000
#define SPACE ' '
#define TAB '\t'
#define TABSIZE 4

int get_line(char line[], int maxline);
void entab(char buffer[], char line[], int tabsize);

int main(void)
{
    char buffer[MAXLINE];
    char line[MAXLINE];

    while (get_line(buffer, MAXLINE) > 0) {
        entab(buffer, line, TABSIZE);
        printf("%s", line);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void entab(char buffer[], char line[], int tabsize)
{
    int i, j, k, l, tabs, spaces, c;

    i = j = k = 0;
    while ((c = buffer[i++]) != '\0') {
        if (c == SPACE) {
            k++;
        } else {
            if (k > 0) {
                spaces = k % tabsize;
                tabs = k / tabsize;
                if (tabs != 0) {
                    for (l = 0; l < tabs; l++) {
                        line[j++] = TAB;
                    }
                }
                if (spaces != 0) {
                    for (l = 0; l < spaces; l++) {
                        line[j++] = SPACE;
                    }
                }
                k = 0;
            }
            line[j++] = c;
        }
    }
}
