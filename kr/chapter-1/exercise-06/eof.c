#include <stdio.h>

int main(void)
{
    printf("Enter a character: ");
    printf("The \"getchar() != EOF\" results in: %d", getchar() != EOF);
    return 0;
}
