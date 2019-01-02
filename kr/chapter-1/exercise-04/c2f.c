#include <stdio.h>

/*
 * print Celsius-Fahrenheit table
 * for celsius = 0, 20, ..., 300
 */

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius\tFahrenheit\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%6.0f\t%10.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
