#include <stdio.h>

#define CHARACTERS_COUNT 26
#define DIGITS_COUNT 10

/* Order of characters in this histogram
 * a b c d e f g h i j k l m n o p q r s t u v w x y z
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 * 1 2 3 4 5 6 7 8 9
 */

int main(void)
{
    int c, biggest, chars_length;
    chars_length = CHARACTERS_COUNT * 2 + DIGITS_COUNT;
    int chars_counts[chars_length];

    for (int i = 0; i < chars_length; i++) {
        chars_counts[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ((c >= 'a') && (c <= 'z'))
            ++chars_counts[c - 97];
        else if ((c >= 'A') && (c <= 'Z'))
            ++chars_counts[c - 65 + CHARACTERS_COUNT];
        else if ((c >= '0') && (c <= '9'))
            ++chars_counts[c - 48 + CHARACTERS_COUNT * 2];

    }

    for (int i = 0; i < chars_length; i++) {
        if (biggest < chars_counts[i])
            biggest = chars_counts[i];
    }

    while (biggest != 0) {
        for (int i = 0; i < chars_length; i++) {
            if (chars_counts[i] >= biggest)
                printf("#");
            else
                printf(" ");
            printf(" ");
        }
        printf("\n");
        --biggest;
    }

    /* lower case characters */
    for (int i = 97; i < 97 + CHARACTERS_COUNT; i++) {
        printf("%c ", i);
    }

    /* upper case characters */
    for (int i = 65; i < 65 + CHARACTERS_COUNT; i++) {
        printf("%c ", i);
    }

    /* digits characters */
    for (int i = 48; i < 48 + DIGITS_COUNT; i++) {
        printf("%c ", i);
    }

    printf("\n");

    return 0;
}
