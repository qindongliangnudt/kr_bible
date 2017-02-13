#include <stdio.h>

int main(int argc, char* argv[])
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -100;
    upper = 200;
    step = 15;

    celsius = lower;
    printf("Celsius\tFahr\n");

    while ( celsius <= upper ) {
        fahr = 9.0*celsius / 5.0 + 32.0;
        printf("%4.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
