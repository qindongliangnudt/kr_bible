#include <stdio.h>
#include <stdlib.h>

/* word counting */

#define IN 1
#define OUT 0

int main( int argc, char* argv[])
{
    int c, nc, nl, nw, state;
    state = OUT;
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
   
    nl = nw = nc = 0;
    while ((c = fgetc(fp)) != EOF) {
        printf("%d ", c);
        ++nc;
        if (c == '\n') {
            putchar(c);
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d\n%d\n%d\n%d\n", c, nc, nl, nw);
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");
    fclose(fp);
    return 0;
}
