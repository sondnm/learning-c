#include <stdio.h>

int main(void)
{
    int c, blank_count;

    blank_count = 0;

    while ((c = getchar()) != EOF)
        if (c == ' ') {
            ++blank_count;
        } else {
            if (blank_count > 0) {
                printf(" ");
                blank_count = 0;
            }
            printf("%c", c);
        }

    return 0;
}
