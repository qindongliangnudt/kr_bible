#include <stdio.h>

/* copy input to output */

int main(int argc, char* argv[])
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
    return 0;
}
