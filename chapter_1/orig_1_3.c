#include <stdio.h>

/* print the Fahrenheit-Celsius table
   using float datatype. 
   for fahr = 0, 20, 40, ..., 300 */

int main(int argc, char* argv[])
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while ( fahr <= upper ) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + 20;
    }

    return 0;
}

