#include <stdio.h>

int f2c(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit\tCelsius\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = f2c(fahr);
        printf("%10.0f\t%7.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
