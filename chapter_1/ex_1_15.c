#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

float temperature_conversion(int);

int main( int argc, char* argv[])
{
    int fahr;
    float cel;

    printf("fahrenheit	celsium\n");

    for ( fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        cel = temperature_conversion( fahr );
        printf("%10d	%6.1f\n", fahr, cel); 
    } 
    return 0;
}

float temperature_conversion( int fahr ) {
    return (5.0/9.0) * (fahr - 32.0);
}
