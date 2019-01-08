#include <stdio.h>
#define MAXLINE 1000
#define BREAKPOINT 4
#define SPACE ' '
#define NEWLINE '\n'

int get_line(char line[], int maxline);
void fold(char buffer[], char line[], int breakpoint);

int main(void)
{
    char buffer[MAXLINE];
    char line[MAXLINE];

    while (get_line(buffer, MAXLINE) > 0) {
        fold(buffer, line, BREAKPOINT);
        printf("%s", line);
    }
    return 0;
}

int get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != NEWLINE; i++) {
        s[i] = c;
    }
    if (c == NEWLINE) {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

void fold(char buffer[], char line[], int breakpoint)
{
    int i, j, k, l, c;

    j = k = l = 0;
    for (i = 0; (c = buffer[i]) != '\0'; i++) {
        if (c == NEWLINE) {
            line[j++] = c;
            k = l = 0;
        } else if (c != SPACE && k != breakpoint) {
            line[j++] = c;
            k++;
        } else if (c != SPACE && k == breakpoint && l != 0) {
            line[l] = '\n';
            line[j++] = c;
            k++;
            l = 0;
        } else if ((c != SPACE && k == breakpoint && l == 0) || (c == SPACE && k == breakpoint)) {
            line[j++] = '\n';
            line[j++] = c;
            k = 1;
            l = 0;
        } else if (c == SPACE && k != breakpoint){
            l = j;
            line[j++] = c;
            k++;
        }
    }
    line[j] = '\0';
}
