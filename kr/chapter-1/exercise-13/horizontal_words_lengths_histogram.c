#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD 10

int main(void)
{
    int c, word_length, position;

    position = word_length = 0;

    while (position < MAX_WORD) {
        c = getchar();
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("\n");
            word_length = 0;
            ++position;
        } else {
            printf("#");
        }
    }

    return 0;
}
