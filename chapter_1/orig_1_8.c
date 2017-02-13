#include <stdio.h>
#include <stdlib.h>

/* count lines */

int main( int argc, char* argv[])
{
    int c, nl;
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
    nl = 0;
    while ((c = fgetc(fp)) != EOF) {
        printf("%d ", c);
        if (c == '\n') {
            putchar(c);
            nl++;
        }
    }
    printf("%d\n%d\n", c, nl);
    return 0;
}
