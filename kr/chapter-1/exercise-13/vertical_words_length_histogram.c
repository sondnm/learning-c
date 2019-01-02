#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD 10

int main(void)
{
    int c, word_length, position, biggest;
    int words_counts[MAX_WORD];

    position = word_length = biggest = 0;

    while (position < MAX_WORD) {
        c = getchar();
        if (c == ' ' || c == '\n' || c == '\t') {
            words_counts[position] = word_length;

            if (word_length > biggest)
                biggest = word_length;

            word_length = 0;
            ++position;
        } else {
            ++word_length;
        }
    }

    while (biggest != 0) {
        for (int i = 0; i < MAX_WORD; i++) {
            if (words_counts[i] >= biggest)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
        --biggest;
    }

    return 0;
}
